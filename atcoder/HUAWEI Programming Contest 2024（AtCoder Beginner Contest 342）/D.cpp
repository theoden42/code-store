

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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long


vector<bool> is_prime(MAX_N + 1, true);;
vector<int> spf(MAX_N + 1);

void sieve(){
	is_prime[0] = is_prime[1] = false;
    spf[0] = 0;
    spf[1] = 1;
    
    for(int i = 2; i <= MAX_N; i++){
        spf[i] = i;
    }

    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i){
                is_prime[j] = false;
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorise(int n){
    vector<int> factors;
    while(n > 1){
        int sf = spf[n];
        int count = 0;
        while(n % sf == 0){
        	count += 1;
            n /= sf;
        }
        if(count & 1){
        	factors.push_back(sf);
        }
    }
    sort(all(factors));
    return factors;
}

void solve() {
	sieve();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int ans = 0;
    map<vector<int>, int> mp;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            count += 1;
            continue;
        }
    	vector<int> temp = factorise(a[i]);
    	ans += mp[temp];
    	mp[temp] += 1;
    }

    ans += (count * (n - count));
    ans += (count * (count - 1) / 2);

    cout << ans << "\n";
}




int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}