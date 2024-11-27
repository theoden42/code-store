

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
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}

	vector<pair<int,int>> end(n, -1);
	vector<int> len(n, 1);
	int mx = 0;
	vector<int> len(n);
	for(int i = 1; i < n - 1; i++){
		if(p[i] > p[i - 1] && p[i] > p[i + 1]){
			int j = i - 1;
			while(j - 1 >= 0 && p[j - 1] < p[j]){
				j -= 1;
			}
			end[i].first = j;
			j = i + 1;
			while(j + 1 < n && p[j + 1] < p[j]){
				j += 1;
			}
			end[i].second = j;
		}
	}
	int mx = 0;
	for(int i = 0; i < n; i++){
		if(end[i].first != -1){
			int l1 = (i - end[i].first + 1);
			int l2 = (end[i].second - i + 1);
			len[i] = max(l1, l2);
			mx = max(mx, len[i]);
		}	
	}

	int count = 0;
	int ind = 0;
	for(int i = 0; i < n; i++){
		if(len[i] == mx){
			ind = i;
			count += 1;
		}
	}
	if(count > 1){
		cout << "0\n";
		return;
	}

	


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}