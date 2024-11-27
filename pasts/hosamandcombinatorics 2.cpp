
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
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int a = 1;
    int b = 1;
    int flag = 1;

    sort(all(ele));
    for(int i = 1; i < n; i++){
    	if(ele[i] != ele[i - 1]){
    		flag = 0;
    		break;
    	}
    }
    if(flag == 1){
    	ll ans = 1ll * (n) * (n - 1);
    	cout << ans << "\n";
    	return;
    }

    for(int i = 1; i < n; i++){
    	if(ele[i] == ele[i - 1]){
    		a++;
    	}
    	else{
    		break;
    	}
    }

    for(int i = n - 2; i >= 0; i--){
    	if(ele[i] == ele[n - 1]){
    		b++;
    	}
    	else{
    		break;
    	}
    }

   ll ans = 2ll * a * b;
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