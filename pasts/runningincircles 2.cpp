
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
    int l, n;
    cin >> l >> n;
    ll count = 0;
    vector<pair<int,char>> runs(n);


    for(int i = 0; i < n; i++){
    	int d;
    	char c;
    	cin >> d >> c;
    	runs[i] = {d, c};
    }


    ll dist = 0;
    for(int i = 0; i < n; i++){

    	if(runs[i].second == 'C'){
    		dist += runs[i].first;
    	}
    	else{
    		dist -= runs[i].first;
    	}
    	debug(runs[i].first, dist);

    	count += abs(dist / l);
    	if(dist < 0){
    		dist = -1 * (abs(dist) % l);
    	}
    	else{
    		dist = dist % l;
    	}
    }
    cout << count << "\n";	

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