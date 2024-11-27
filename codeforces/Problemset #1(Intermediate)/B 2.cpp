
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
    int na, nb, nc;
    cin >> na >> nb >> nc;

    vector<int> r, g, b;
    for(int i = 0; i < na; i++){
    	int x;
    	cin >> x;
    	r.push_back(x);
    }
    for(int i = 0; i < nb; i++){
    	int x;
    	cin >> x;
    	g.push_back(x);
    }
    for(int i = 0; i < nc; i++){
    	int x;
    	cin >> x;
    	b.push_back(x);
    }


    sort(all(r));
    sort(all(g));
    sort(all(b));
    for(int i = 0; i < na; i++){
    	// make 6 brute forces cases;;
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