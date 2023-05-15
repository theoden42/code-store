
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
    int q;
    cin >> q;
    int count = 0;
    string s1, s2;
    for(int i = 0; i < n; i++){
    	s1 += s[i];
    }
    for(int i = n; i < 2 * n; i++){
    	s2 += s[i];
    }
    debug(s1, s2);

    for(int i = 0; i < q; i++){
    	int t, a, b;
    	cin >> t >> a >> b;
    	if(t == 1){
    		if(count & 1){
    			if(a <= n && b <= n){
    				swap(s2[a - 1], s2[b - 1]);
    			}
    			else if(a > n && b > n){
    				swap(s1[a - n - 1], s1[b - n - 1]);
    			}
    			else{
    				swap(s2[a - 1], s1[b - n - 1]);
    			}

    		}
    		else{
    			if(a <= n && b <= n){
    				swap(s1[a - 1], s1[b - 1]);
    			}
    			else if(a > n && b > n){
    				swap(s2[a - n - 1], s2[b - n - 1]);
    			}
    			else{
    				swap(s1[a - 1], s2[b - n - 1]);
    			}
    		}
    	}
    	else{
    		count++;
    	}
    	debug(s1, s2, count);
    }
    if(count & 1){
    	cout << s2 << s1 << "\n";
    }
    else{
    	cout << s1 << s2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}