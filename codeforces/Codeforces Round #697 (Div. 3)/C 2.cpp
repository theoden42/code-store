
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
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> ar(k);
    vector<int> br(k);

    map<int,int> mpa;
    map<int,int> mpb;

    for(int i = 0; i < k; i++){
    	cin >> ar[i];
    	mpa[ar[i]]++;
    }
    for(int i = 0; i < k; i++){
    	cin >> br[i];
    	mpb[br[i]]++;
    }

	ll count = (1ll * k * (k - 1)) / 2;


	for(int i = 1; i <= a; i++){
		int x = mpa[i];
		ll ways = (1ll * x * (x - 1)) / 2;
		count -= ways;
	}

	for(int i = 1; i <= b; i++){
		int y = mpb[i];
		ll ways = (1ll * y * (y - 1)) / 2;
		count -= ways;
	}

	cout << max(0ll, count) << "\n";

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