
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
	vector<int> freq(10, 0);


	ll count = 0;

	map<int,int> mp;

	mp[0] = 1;

	for(int i = 0; i < n; i++){
		freq[s[i] - '0']++;
		int mask = 0;
		for(int j = 0; j < 10; j++){
			if(freq[j] & 1){
				mask |= (1 << j);
			}
		} 


		count += mp[mask];
		mp[mask]++;
	}


	cout << count << "\n";

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