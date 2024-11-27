
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
    int n, k, x, d;
    int m;
    cin >> n >> k >> x >> d;
    cin >> m;
    vector<vector<pair<int,int>>> meetings(n);
    for(int i = 0; i < m; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
    	meetings[a - 1].push_back({b, c});
    }
    int mn = m + 1;
	for(int i = 0; i <= d - x; i++){
		vector<int> cancel(n, 0);
		for(int j = 0; j < n; j++){
			int count = 0;
			for(auto& y: meetings[j]){
				if((y.first < i + x && y.second > i)){
					count++;
				}
			}
			cancel[j] = count;
		}
		sort(all(cancel));

		int temp = 0;
		for(int i = 0; i < k; i++){
			temp += cancel[i];
		}
		mn = min(mn, temp);
	}
	cout << mn << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}