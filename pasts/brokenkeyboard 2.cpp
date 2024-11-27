    
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
  int n;
  cin >> n;
  string s;
  cin >> s; 

  int time = 1;

  for(int i = 0; i < n; i++){
    if(time % 2 == 0){
        if(i == n - 1){
            cout << "NO\n";
            return;
        }
        if(s[i] == s[i + 1]){
            i++;
            time++;
            continue;
        }
        cout << "NO\n";
        return;
    }
    else{
        time++;
    }
  }  
  cout << "YES\n";
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