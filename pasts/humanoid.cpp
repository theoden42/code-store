
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


ll countmen(int index, ll h, int c1, int c2, vector<ll>& ele){


	if(index == ele.size())return 0;

	if(ele[index] < h){
		return countmen(index + 1, h + ele[index] / 2, c1, c2, ele) + 1;
	}

    ll mx = 0;
	if(c1 > 0)
		mx =  max(mx, countmen(index, 2 * h, c1 - 1, c2, ele));
	if(c2 > 0)
		mx = max(mx, countmen(index, 3 * h, c1, c2 - 1, ele));

	return mx;

}

void solve() {
    ll n;
    cin >> n;
    ll h;
    cin >> h;
    vector<ll> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    sort(all(ele));
    ll count = countmen(0, h, 2, 1, ele);


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