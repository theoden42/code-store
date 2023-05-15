
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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> nf(m);

    vector<set<int>> notfriend(n + 1);


    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	nf[i] = {x, y};
    	notfriend[max(x, y)].insert(min(x, y));
    }


    ll count = n;
    int last = 1;

    for(int i = 2; i <= n; i++){
   		// include in pair only when the last is included
   		auto it = lower_bound(all(notfriend[i]), last);
   		if(it != notfriend[i].end()){
   			last = *(--notfriend[i].end()) + 1;
   		}
   		count = count + i - last;
	   	debug(i, count);

    }
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