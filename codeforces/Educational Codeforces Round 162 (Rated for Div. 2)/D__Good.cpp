

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n, 1e9);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){

        if(i < n - 1 && a[i + 1] > a[i]){
            ans[i] = 1;
            continue;
        }
        if(i > 0 && a[i - 1] > a[i]){
            ans[i] = 1;
            continue;
        }   

        int sum1 = 0;
        set<int> st;
        for(int j = i + 1; j < n; j++){
            sum1 += a[j];
            st.insert(a[j]);
            if(st.size() == 1 || sum1 <= a[i])
                continue;
            else{
                ans[i] = min(ans[i], j - i);
                break;
            }
        }
        sum1 = 0;
        st.clear();
        for(int j = i - 1; j >= 0; j--){
            sum1 += a[j];
            st.insert(a[j]);
            if(st.size() == 1 || sum1 <= a[i])
                continue;
            else {
                ans[i] = min(ans[i], i - j);
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ((ans[i] == 1e9) ? -1 : ans[i]) << " \n"[i == n - 1];
    }
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