
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
	int n, q;
	cin >> n >> q;
	set<int> ncall;
	set<int> ncome;

	for(int i = 1; i <= n; i++){
		ncall.insert(i);
	}

	for(int i = 1; i <= q; i++){
		int t;
		cin >> t;
		if(t == 1){
			int x = *ncall.begin();
			ncall.erase(ncall.begin());
			ncome.insert(x);
		}
		else if(t == 2){
			int x;
			cin >> x;
			ncome.erase(ncome.find(x));
		}
		else{
			assert(!ncome.empty());
			int x = *ncome.begin();
			cout << x << "\n";
		}
	}

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