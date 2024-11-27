

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

const int MAX_N = 2e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<vector<T>> range_min;
    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }
    void build(const vector<T> &values) {
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_min.resize(levels);
        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);
        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }
    void show() const {
        for (int i = 0; i < int(range_min.size()); i++) {
            for (int j = 0; j < int(range_min[0].size()); j++) {
                cout << range_min[i][j] << " \n"[j + 1 == range_min[0].size()];
            }
        }
    }
    T query_value(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = highest_bit(to - from + 1);
        return better(range_min[lg][from], range_min[lg][to - (1 << lg) + 1]);
    }
};


vector<bool> is_prime(MAX_N + 1, true);;
vector<int> spf(MAX_N + 1);
vector<int> max_fac(MAX_N + 1);

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
        while(n % sf == 0){
            factors.push_back(sf);
            n /= sf;
        }
    }
    return factors;
}





void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    multiset<pair<int,int>> mst;
    vector<int> first(n);
    for(int i = 0; i < n; i++){
        if(a[i] != 1)
            mst.insert({a[i], -i});
        else 
            first[i] = 0;
    }

    int count = 1;
    while(!mst.empty()){
        auto it = *(--mst.end());
        mst.erase(--mst.end());

        int mx = max_fac[it.first];
        it.first /= mx;
        if(it.first == 1){
            first[-it.second] = count;
        }else{
            mst.insert(it);
        }
        count++;
    }


    RMQ<int,true> r(first);
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << r.query_value(x, y) << "\n";
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    sieve();

    max_fac[1] = 1;
    for(int i = 2; i <= MAX_N; i++){
        vector<int> v = factorise(i);
        int mx = *max_element(all(v));
        max_fac[i] = mx;
    }

    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}