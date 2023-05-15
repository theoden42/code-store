
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
const ll MOD = 998244353;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    int count = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	if(ele[i] == 1){
    		count++;
    	}
    }


    vector<int> temp;
    vector<int> even;

    for(int i = 0; i < n; i++){
    	if(ele[i] == 1)continue;
    	if(ele[i] & 1)temp.push_back(ele[i]);
    	else even.push_back(ele[i]);
    }

    sort(even.begin(), even.end());
    for(int i = 0; i < even.size(); i++){
    	if(count > 0){
    		temp.push_back(even[i] + 1);
    		count--;
    	}
    	else{
    		temp.push_back(even[i]);
    	}
    }
    ll ans = 1;
    for(auto& x: temp){
    	ans = (1ll * ans * x) % MOD;
    }
    cout << ans << "\n";

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