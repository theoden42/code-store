
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
   vector<pair<int,int>> rooks(m);
   map<int,int> mpr;
   map<int,int> mpc;
   for(int i = 0; i < m; i++){
   		int x, y;
   		cin >> x >> y;
   		rooks[i] = {x, y};
   		mpr[x]++;
   		mpc[y]++;
   }
   for(int i = 1; i <= n; i++){
   		if(mpr.find(i) == mpr.end() || mpr[i] == 0){
   			cout << "YES" << "\n";
   			return;
   		}
   }
   for(int j = 1; j <= n; j++){
   		if(mpc.find(j) == mpc.end() || mpc[j] == 0){
   			cout << "YES" << "\n";
   			return;
   		}
   }
   cout << "NO" << "\n";

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