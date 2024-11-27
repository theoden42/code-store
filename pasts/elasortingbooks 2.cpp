
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> freq(26, 0);

    for(int i = 0; i < n; i++){
    	freq[s[i] - 'a']++;
    }

   	int c = 25;
   	int count = k;
   	string ans = "";
	for(int i = 0; i < 25 && i < n / k; i++){
		debug(freq, count);
		if(freq[i] >= count){
			continue;
		}
		else{
			int val = count - freq[i];
			for(int j = 0; j < val; j++){
				ans = (char)('a' + i) + ans;
			}
			count = freq[i];
		}
	}
	for(int i = 1; i <= count; i++){
		ans = (char)('a' + min(25, n / k)) + ans;
	}
	cout << ans << "\n"; 
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