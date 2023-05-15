
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int d, n, x;
    cin >> d >> n >> x;
    vector<pair<int,pair<int,int>>> seeds(n);
    for(int i = 0; i < n; i++){
    	int a, b, c;
    	cin >> a;
    	cin >> b;
    	cin >> c;
    	seeds[i] = {c, {a, b}};
    }
    sort(all(seeds));
    reverse(all(seeds));
    debug(seeds);

    int profit = 0;	
    int left = 0;
    int day = 0;

    for(int i = 0; i < n && day < d; i++){
    	debug(day, profit);
    	if(day + seeds[i].second.second >= d){
    		continue;
    	}
    	else if(left != 0){
    		profit += min(left, seeds[i].second.first) * seeds[i].first;
    		left -= min(left, seeds[i].second.first);
    		seeds[i].second.first -= min(left, seeds[i].second.first);
    		if(left == 0){
    			day++;
    		}
    	}
    	int val1 = ceil(seeds[i].second.first / x);
    	if(val1 > d - day){
    		profit += seeds[i].first * (x * (d - day));
    		day = d;
    	} 
    	else{
    		profit += seeds[i].first * seeds[i].second.first;
    		day += seeds[i].second.first / x;
    		left = seeds[i].second.first % x;
    		if(left != 0)day--;
    	}
    }
    cout << profit << "\n";


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}