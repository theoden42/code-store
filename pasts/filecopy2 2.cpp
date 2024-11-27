
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
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> prefix(n + 1, 0);

    for(int i = 1; i <= n; i++){
    	prefix[i] = prefix[i - 1] + ele[i - 1];
    }

    int sum = prefix[n];
    debug(sum);
    vector<int> ans;

    for(int j = 0; j <= 100; j++){

    	int lval = ceil((j * sum) / 100.0);
    	int temp = (lval * 100 / sum); 
    	if(temp != j)continue;

    	for(int i = 0; i < n; i++){

    		int lvalt = lval - prefix[i];
    		int v1 = ceil((j * ele[i]) / 100.0);
    		temp = (v1 * 100 / ele[i]);
    		debug(temp, v1, j, lvalt);

    		if(temp != j)continue;
    		
    		if(v1 == lval){
    			ans.push_back(j);
    			break;
    		}
    	}
    }

    for(auto& x: ans){
    	cout << x << "\n";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}