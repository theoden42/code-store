
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


    vector<int> p(n);
    for(int i = 0; i < n; i++){
    	if(s[i] == 'T')p[i] = 1;
    	else p[i] = 0;
    }
    int count = 0;
    for(int i = n - 1; i > 0; i--){
    	int val = (p[i] ^ p[i - 1]);
    	if(!val)count++;
    }
    if(p[0] == 0)count++;
    cout << count << "\n";
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