

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
#define int int64_t

void solve() {
	int n;
	cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    // if I add a[i] to the sequence than the sequence mex right now can be 
    // a[i] - 1 -> mex doesnot change, a[i] -> mexchanges, a[i] + 1 -> mex doesnot changse
    // if the sequence is good, and it has mx x then no element greater than x + 1 ever exists in the array 
    // what if x + 1 exists in the array, the problem would occur when we will have a[i] as mex 
    // so we will have to store the array such that the mex is x and x + 1 does not exist in the array;
    vector<int> mex(n + 2); // number of good sequences with atleast one greater element than x
    vector<int> mexx(n + 2); // number of good sequence with no greater element than x

    mexx[0] = 1;

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            ans += mex[a[i] - 1]; // I don't care how many are there ? 
            ans %= MOD;    
            ans += mexx[a[i] - 1];
            ans %= MOD; 
        }
        ans += mex[a[i] + 1]; // I don't care about x + 1 type of elements
        ans %= MOD;
        ans += mexx[a[i] + 1]; // mexx contains sequences with no element greater than x contained in mex sequence of x;
        ans %= MOD;
        ans += mexx[a[i]];
        ans %= MOD;

        if(a[i] > 0){
            mex[a[i] - 1] *= 2;
            mex[a[i] - 1] %= MOD;
            mex[a[i] - 1] += mexx[a[i] - 1];
            mex[a[i] - 1] %= MOD;
        }

        mex[a[i] + 1] *= 2;
        mex[a[i] + 1] %= MOD;   
        mexx[a[i] + 1] *= 2;
        mexx[a[i] + 1] %= MOD;

        mexx[a[i] + 1] += mexx[a[i]];
        mexx[a[i] + 1] %= MOD;
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