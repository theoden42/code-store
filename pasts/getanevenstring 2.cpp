
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
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> prefix(n, vector<int>(26, -1));
	prefix[n - 1][s[n - 1] - 'a'] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			if(j == s[i] - 'a'){
				prefix[i][j] = i;
			}
			else{
				prefix[i][j] = prefix[i + 1][j];
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i == n - 1){
			ans += 1;
			continue;
		}
		if(s[i] == s[i + 1]){
			i++;
			continue;
		}
		else{
			int min = n - 1;
			int flag = 0;
			for(int j = i; j <= min - 1; j++){
				if(prefix[j + 1][s[j] - 'a'] <= min && prefix[j + 1][s[j] - 'a'] != -1){
					min = prefix[j + 1][s[j] - 'a'];
					flag = 1;
				}
			}	
			if(flag == 0){
				ans += n - i;
				break;
			}
			else{
				ans += min - i - 1;
				i = min;
			}
		}

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