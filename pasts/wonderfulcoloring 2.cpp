
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


int ans[MAX_N];
map<int, vector<int>> indices;

void solve(){

	int n, k;
		cin >> n >> k;
		indices.clear();
		memset(ans, 0, n * sizeof(ans[0]));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (indices[x].size() < k)
				indices[x].push_back(i);
		}
		int m = 0;
		for (auto e : indices) m += e.second.size();
		m -= m % k;
		int color = 0;
		for (auto e : indices)
			for (auto i : e.second)
			{
				ans[i] = ++color;
				color %= k;
				if (--m == 0) goto _output;
			}
	_output:
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}