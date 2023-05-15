

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
	vector<int> a(n);


	map<int,int> mp;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}

	int m = 0;

	for(int i = 0; i <= n; i++){
		if(mp[m] == 0){
			break;
		}
		else{
			m++;
		}
	}

	if(mp[m + 1] == 0){
		for(int i = 0; i < n; i++){
			if(mp[a[i]] >= 2 || a[i] > m + 1){
				cout << "Yes\n";
				return;
			}
		}
		cout << "No\n";
	}

	else{
		int ind = 0;

		int l = -1;
		int r = -1;

		for(int i = 0; i < n; i++){
			if(a[i] == m + 1){
				if(l == -1){
					l = i;
				}
				r = i;
			}
		}

		for(int i = l; i <= r; i++){
			a[i] = m;
		}

		mp.clear();

		for(int i = 0; i < n; i++){
			mp[a[i]]++;
		}
		
		int m2 = 0;
		for(int i = 0; i <= n; i++){
			if(mp[m2] == 0)break;
			else{
				m2++;
			}
		}	
		if(m2 == m + 1){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}

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