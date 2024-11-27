

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

const int MAX_N = 200020;
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

vector<int> sf(MAX_N, 0);
vector<int> factorial(MAX_N, 0);

void preprocess(){
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b=MOD){
    return binpow(a, b - 2) % MOD;
}


template<typename T>
struct SegTree {

    int sz = 1;
    vector<T> arr;
    T iden = 0;
   
    T combine(T a, T b){
         T temp;    
        // how to combine two nodes
         temp = (a + b) % MOD;
         return temp ;
    }
     T single_value(int v){
        // what to store in leaves corresponding to array value v
        return v % MOD;
    }
    
    void init(int n){
        while(sz < n){
            sz *= 2;
        }
        arr.resize(2 * sz, iden);
    }

    void build(vector<int>& a){
        build(a, 0, 0, sz);
    }

    void set(int ind, int value){
        setUtil(ind, value, 0, 0, sz);
    }

    T get(int l, int r){
        return getUtil(l, r, 0, 0, sz);
    }

    void build(vector<int>& a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                arr[x] = single_value(a[lx]);
            }    
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
    }

    T getUtil(int l, int r, int x, int lx, int rx){
        if(lx >= l && rx <= r){
            return arr[x];
        }
        else if(lx >= r || rx <= l){
            return iden;
        }
        int m = (lx + rx) / 2;
        T left = getUtil(l, r, 2 * x + 1, lx, m);
        T right = getUtil(l, r, 2 * x + 2, m, rx);
        return combine(left, right);
    }

    void setUtil(int ind, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x] = single_value(val);
            return;
        }

        int m = (lx + rx) / 2;
        if(ind < m){
            setUtil(ind, val, 2 * x + 1, lx, m);
        }
        else{
            setUtil(ind, val, 2 * x + 2, m, rx);
        }

        arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sf[x]++;
        s[i] = x;
    }
    for(int i = 0; i < m; i++){
        cin >> t[i];

    }

    int total = factorial[n];

    for(int i = 1; i < MAX_N; i++){
        total *= modinverse(factorial[sf[i]]);
        total %= MOD;
    }

    int previous = total;  

    int rem = n;
    SegTree<int> st;
    st.init(MAX_N);
    st.build(sf);
    
    for(int i = 0; i < n; i++){
        if(i >= m){
            total -= previous; 
            total += MOD;
            total %= MOD;
            break;
        }
        else{
            previous *= modinverse(factorial[rem]);
            previous %= MOD;
            previous *= factorial[rem - 1];
            previous %= MOD;

            int x = t[i];
            int temval = (previous * (st.get(x + 1, MAX_N))) % MOD; 
            total -= (temval);
            total += MOD;
            total %= MOD;

            if(sf[x] > 0){
                previous *= (factorial[sf[x]]) % MOD;
                previous %= MOD;
                sf[x]--;
                previous *= modinverse(factorial[sf[x]]);
                previous %= MOD;
                st.set(x, sf[x]);
                rem--;
            }
            else{
                break;
            }
        }

    }

    sort(all(s));sort(all(t));

    if(s == t){
        total -= 1;
        total += MOD;
        total %= MOD;
    }


    cout << total << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}