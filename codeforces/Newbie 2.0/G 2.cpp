
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
	int w, m;
	cin >> w >> m;
	map<int,vector<int>> mp;


	int sum = 0;
	for(int i = 0; i < w; i++){
		sum += s[i] - '0';
	}

	mp[sum % 9].push_back(0);
	for(int i = 1; i < n - w + 1; i++){
		sum -= (s[i - 1] - '0');
		sum += (s[i + w - 1] - '0');
		mp[sum % 9].push_back(i);
	}

	vector<int> prefix(n);
	prefix[0] = s[0] - '0';

	for(int i = 1; i < n; i++){
		prefix[i] = prefix[i - 1] + (s[i] - '0');
	}

	for(int i = 1; i <= m; i++){
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		r--;

		int t_sum = prefix[r] - prefix[l] + s[l] - '0';
		int a1 = INF;
		int a2 = INF;

		for(int j = 0; j <= 8; j++){
			for(int j2 = 0; j2 <= 8; j2++){
				int rem = ((j * (t_sum % 9)) % 9 + j2) % 9;


				if(mp.find(j) != mp.end() && mp.find(j2) != mp.end() && rem == k){

					if(j == j2 && mp[j].size() < 2){
						continue;
					}
					int ind1 = mp[j][0];
					int ind2 = (j == j2) ? mp[j][1] : mp[j2][0];

					if(ind1 < a1){
						a1 = ind1;
						a2 = ind2;
					}
					else if(ind1 == a1 && ind2 < a2){
						a1 = ind1;
						a2 = ind2;
					}
				}
			}
		}
		if(a1 == INF){
			cout << "-1 -1\n";
		}
		else{
			cout << a1 + 1 << " " << a2 + 1 << "\n";
		}
	}
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