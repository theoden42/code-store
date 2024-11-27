

/* author: (g)theoden42 */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

// template<typename T>
// using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int query(int i){
	cout << "? " << i + 1 << endl;;
	char c;
	cin >> c;
	if(c == '=')
		return 0;
	else if(c == '<')
		return -1;
	else if(c == '>')
		return 1;
	else 
		return 0;
};

void sort(int l, int r, vector<int>& index){
	debug(l, r, index);
	if(r < l)
		return;
	int ind = l + (rng() % (r - l + 1));
	int val = -1;
	while(val != 0){
		val = query(index[ind]);
	}
	vector<int> left, right;
	for(int i = l; i <= r; i++){
		val = query(index[i]);
		if(val == -1){
			left.push_back(index[i]);
		} else if(val == 1){
			right.push_back(index[i]);
		}
		query(index[ind]);
	}
	int i = l;	
	int t = index[ind];
	for(int j = 0; j < left.size(); j++){
		index[i++] = left[j];
	}
	index[i++] = t;
	for(int j = 0; j < right.size(); j++){
		index[i++] = right[j];
	}
	sort(l, l + left.size() - 1, index);
	sort(l + left.size() + 1, r, index);
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	a[i] = i;
    }
    sort(0, n - 1, a);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
    	ans[a[i]] = i + 1;
    }
    cout << "! ";
    for(auto x: ans){
    	cout << x << " ";
    }
    cout << endl;
}	


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}