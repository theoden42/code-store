

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


void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }
    int count = 0;

    // first line is
    // x = c;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	mp[x[i]]++;
    }
    for(auto it: mp){
    	int freq = it.second;
    	int sum = freq * (freq - 1);
    	count += sum;
    }
    mp.clear();
    
    // second line:
    // y = c;
    for(int i = 0; i < n; i++){
    	mp[y[i]]++;
    }
    for(auto it: mp){
    	int freq = it.second;
    	int sum = freq * (freq - 1);
    	count += sum;
    }
    mp.clear();

    // third line is x + y = c
    for(int i = 0; i < n; i++){
    	int s = x[i] + y[i];
    	mp[s]++;
    }
    for(auto it: mp){
    	int freq = it.second;
    	int sum = freq * (freq - 1);
    	count += sum;
    }
    mp.clear();

    //fourth line is x - y = c
    for(int i = 0; i < n; i++){
    	int s = x[i] - y[i];
    	mp[s]++;
    }
    for(auto it: mp){
    	int freq = it.second;
    	int sum = freq * (freq - 1);
    	count += sum;
    }
    mp.clear();


    cout << count << "\n";

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