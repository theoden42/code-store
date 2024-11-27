

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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
        	cin >> a[i];
        }
        set<int> st;
        for(int i = 0; i < n; i++){
        	cin >> b[i];
        	st.insert(b[i]);
        }

        for(int i = 0; i < n; i++){
            if(a[i] == b[i])
                continue;

            int ind = -1;
            for(int j = i; j >= 0; j--){
                if(a[j] == b[i]){
                    ind = j;
                    break;
                }
            }

            int ind2 = -1;
            for(int j = i; j < n; j++){
                if(a[j] == b[i]){
                    ind2 = j;
                    break;
                }
            }

            int f1 = 1, f2 = 1;
            if(ind != -1){
                for(int k = ind; k < i; k++){
                    if(b[k] < b[i] || a[k] > b[i]){
                        f1 = 0;
                        break;
                    }
                }
            } else {
                f1 = 0;
            }
            if(ind2 != -1){
                for(int k = i; k < ind2; k++){
                    if(b[k] < b[i] || a[k] > b[i]){
                        debug(b[k], b[i], a[k]);
                        f2 = 0;
                        break;
                    }
                }
            } else {
                f2 = 0;
            }
            debug(ind, ind2);
            if(!f1 && !f2){
                debug(i);
                cout << "NO\n";
                return;
            }

        }
        cout << "YES\n";
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