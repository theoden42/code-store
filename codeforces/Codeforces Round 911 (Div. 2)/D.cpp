

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
    while(n != 1){
        int sf = spf[n];
        factors.push_back(sf);
        while(n % sf == 0){
            n /= sf;
        }
    }
    return factors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    debug(a);
    sort(all(a));
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                mp[j].push_back(i);
                if(a[i] / j != j){
                    mp[a[i] / j].push_back(i);
                }
            }
        }
    }

    debug(mp[1]);

    int mx = *max_element(all(a));
    vector<int> triples(mx + 1);
    for(int i = mx; i >= 1; i--){
        int pos = 0;
        int total = 0;
        if(mp.find(i) == mp.end())
            continue;
        for(auto ind: mp[i]){
            int prv = pos;
            int next = (n - 1 - ind);
            total += (pos * next);
            pos += 1;
        }
        for(int j = 2; j * i <= mx; j++){
            total -= triples[i * j];
        }

        triples[i] = total;
    }
    int ans = 0;
    for(int i = 1; i <= mx; i++){
        ans += (i * triples[i]);
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    sieve();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}