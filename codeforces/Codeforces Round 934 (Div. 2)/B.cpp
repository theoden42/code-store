

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);	
	map<int,int> l, r;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		l[a[i]] += 1;
	}
	for(int j = 0; j < n; j++){
		cin >> b[j];
		r[b[j]] += 1;
	}

	vector<int> lonce, ronce, ltwo, rtwo;
	for(int i = 1; i <= n; i++){
		if(l[i] == 1){
			lonce.push_back(i);
		}
		if(l[i] == 2){
			ltwo.push_back(i);
		}
		if(r[i] == 1){
			ronce.push_back(i);
		}
		if(r[i] == 2){
			rtwo.push_back(i);
		}
	}

	vector<int> left(2 * k), right(2 * k);
	int count = 0;

	for(int i = 0; i < ltwo.size() && count + 1 < 2 * k; i++){
		left[count] = ltwo[i];
		left[count + 1] = ltwo[i];
		right[count] = rtwo[i];
		right[count + 1] = rtwo[i];
		count += 2;
	}

	for(int i = 0; i < lonce.size() && count < 2 * k; i++){
		left[count] = lonce[i];
		right[count] = ronce[i];
		count += 1;
	}

	for(auto a: left){
		cout << a << " ";
	}
	cout << "\n";
	for(auto b: right){
		cout << b << " ";
	}
	cout << "\n";
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