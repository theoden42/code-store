
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    int f = 0;


   	for(int i = 1; i <= n; ++i){
   		for(int j = 1; j <= m; j++){
   			if(i % 2 == 1){
   				cout << "#";
   				continue;
   			}
   			else {
   				if(f == 0 && j == m){
   					cout << "#";
   					continue;
   				}
   				else if(f == 1 && j == 1){
   					cout << "#";
   					continue;
   				}
   			}
   			cout << ".";
   		}
   		if(i % 2 == 0)
   			f = (f + 1) % 2;
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