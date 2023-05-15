
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
    int day = d;
    int profit = 0;
    while(day >= 1){
    	int max = -1;
    	int index = -1;
    	for(int i = 0; i < n; i++){
    		if(seeds[i].first != -1){
    			if(day + seeds[i].second.second <= d){
    				if(seeds[i].first > max){
    					max = seeds[i].first;
    					index = i;
    				}
    			}
    		}
    	}
    	if(index != -1){
    		profit += seeds[index].first;
    		seeds[index].first = -1;
    	}    	
    	day--;
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