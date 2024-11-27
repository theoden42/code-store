

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
	ll val = (n * (n + 1)) / 2;
	if(val & 1){
		cout << "NO\n";
	}
	else{
		int i = 1;
		int j = n;
		vector<int> a, b;
		int count = 1;

		if(n & 1){
			a.push_back(n);
			b.push_back(n / 2);
			b.push_back(n / 2 + 1);
			int count = 1;
			while(count < n / 2){
				if(count & 1){
					a.push_back(count);
					a.push_back(n - count);
					count += 1;
				}
				else{
					b.push_back(count);
					b.push_back(n - count);
					count += 1;
				}
			}

		}
		else{
			int count = 1;
			while(count <= n / 2){
				if(count & 1){
					a.push_back(count);
					a.push_back(n - count + 1);
					count += 1;
				}
				else{
					b.push_back(count);
					b.push_back(n - count + 1);
					count += 1;
				}

			}
		}
	
		cout << "YES\n";
		cout << a.size() << "\n";
		for(int i = 0; i < a.size(); i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		cout << b.size() << "\n";
		for(int i = 0; i < b.size(); i++){
			cout << b[i] << " ";
		}
		cout << "\n";
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