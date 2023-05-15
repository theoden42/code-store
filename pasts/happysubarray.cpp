
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
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    ll sum = 0;

    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
    	prefix[i + 1] = ele[i] + prefix[i];
    }

    vector<ll> preprefix(n + 1, 0);
    preprefix[0] = prefix[0];

    for(int i = 1; i <= n; i++){
    	preprefix[i] = preprefix[i - 1] + prefix[i];
    }


    debug(prefix, preprefix);
    ll ans = 0;
    vector<int> nsi(n + 1, -1);

    auto nextsmaller = [&](){
    	stack<pair<int,int>> s;
    	for(int i = 0; i <= n; i++){
    		int next = prefix[i];
    		if(s.empty()){
    			s.push({next, i});
    			continue;
    		}
    		while(!s.empty() && s.top().first > next){
    			nsi[s.top().second] = i;
    			s.pop();
    		}
    		s.push({next, i});
    	}
    	while(!s.empty()){
    		nsi[s.top().second] = -1;
    		s.pop();
    	}
    };

    nextsmaller();
    debug(nsi);

    for(int i = 0; i <= n; i++){
    	if(ele[i] < 0)continue;
    	int x = nsi[i];
    	if(x == -1){
    		ans += (preprefix[n] - preprefix[i] + prefix[i]) - (prefix[i] * (n - i + 1));
    	}
    	else{
    		ans += (preprefix[x - 1] - preprefix[i] + prefix[i]) - ((prefix[i]) * (x - i));
    	}
    	debug(i, x, ans);
    }


    cout << ans << "\n";

    debug(nsi);

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