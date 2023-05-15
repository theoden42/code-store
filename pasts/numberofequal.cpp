
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }
    int i = 0, j = 0;

    vector<int> ans(n, 0);

    while(i < n){
    	int count = 0;
    	 if(i != 0 &&  a[i] == a[i - 1]){
    		ans[i] = ans[i - 1];
    		i++;
    		continue;
    	}
    	while(j < m && b[j] <= a[i]){
    		if(b[j] == a[i])
    			count++;
    		j++;
    	}
    	ans[i] = count;
    	i++;
    }
    ll sum = 0;
    for(auto& x: ans){
    	sum += x;
    }
    cout << sum << "\n";	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}