

    /* author: (g)theoden42 */

    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    using namespace std;
    using namespace __gnu_pbds;

    #define all(a) a.begin(), a.end()
    #ifdef ON_PC
        #include <debug.h>
    #else
        #define debug(x...)
    #endif

    template<typename T>
    using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    using ll =  long long;
    using ld = long double;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    const int MAX_N = 1e6 + 5;
    const ll MOD = 998244353;
    const ll INF = 1e9;

    #define int long long

    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
        	cin >> a[i];
        }
        int lst = 0;
        for(int i = 0; i < n; i++){
        	if(a[i] > i + 1 || a[i] > lst + 2 || a[i] < lst){
        		cout << "0\n";
        		return;
        	}
        	lst = a[i];
        }
        if(a.back() != n){
        	cout << "0\n";
        	return;
        }
        int count = 0;
        int curr = 0;
        int rem = 0;
        int ans = 1;
        for(int i = 0; i < n; i++){
        	if(a[i] == curr){
        		rem += 1; // values left to use
        		count += 1; // places left;
        	} else if(a[i] == curr + 1){
        		// use a lower value // use current value in left places;
        		int num = rem + count + 1;	
        		// debug(num);
        		ans *= num;
        		ans %= MOD;
        	} else { 
        		// use a lower value somewhere and current_value in one of previous places 
        		int num = (count * rem);
        		// debug(num, rem, count);
        		num %= MOD;
        		ans *= num;
        		ans %= MOD;
        		rem -= 1;
        		count -= 1;
        	}
        	curr = a[i];
        }

        cout << ans << "\n";
    }


    int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int tc = 1;
        cin >> tc;
        for (int t = 1; t <= tc; t++) {
            // cout << "Case #" << t << ": ";
            solve();
        }
    }