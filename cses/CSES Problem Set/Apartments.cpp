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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;

const ll INF = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int j = 0; j < m; j++){
    	cin >> b[j];
    }
    sort(all(a));
    sort(all(b));
    debug(a, b);

    int j = 0;
    int count = 0;
    for(int i = 0; i < n && j < m; i++){
        debug(i, j);
    	if(b[j] >= a[i] - k && b[j] <= a[i] + k){
    		count++;
    		j++;
    	}
   		else if(b[j] > a[i] + k){
   			continue;
   		} 
   		else{
   			while(b[j] < a[i] - k && j < m){
   				j++;
   			}
   			i -= 1;
   		}
    }
    cout << count << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
