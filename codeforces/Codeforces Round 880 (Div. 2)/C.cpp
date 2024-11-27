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

    ll binpow(ll a, ll b)
    {
        ll ans = 1;
        while(b){
            if(b & 1){
                ans = (ans * a);
            }
            a = (a * a);
            b = b >> 1; 
        }
        return (ans);
    }


    // #define int long long

    void solve() {
        int a, b, c, k;
        cin >> a >> b >> c >> k;

        if(c < max(a, b) || c > max(a, b) + 1){
            cout << "-1\n";
            return;
        }

        auto how_many = [&](int x)->int{
            int mx = binpow(10, max(a, b));
            int y = mx - x; // min number to make c + 1
            int total = 0;
            string temp = to_string(y);

            if(temp.size() > b){
                total = 0;
            }
            else if(temp.size() < b){
                total = 9 * binpow(10, b - 1);
            } 
            else{
                total = binpow(10, b) - y;
            }

            if(c == max(a, b) + 1){
                return total;
            }
            else{
                int temp = 9 * binpow(10, b - 1) - total;
                return temp;
            }
        };

        int mn = binpow(10, a - 1);
        int mx = binpow(10, a);

        // debug(a, b, c);

        for(int i = mn; i < mx; i++){
            // the values  of A, how many values of B possible ? 
            int val2 = how_many(i);
            // debug(val2);
            if(val2 < k){
                k = k - val2;
                continue;
            }
            else{
                int mn1 = binpow(10, b - 1);
                int mx1 = binpow(10, b);
                int count = 0;
                for(int j = mn1; j < mx1; j++){
                    int t = i + j;
                    string x = to_string(t);
                    if(x.size() == c){
                        count++;
                        if(count == k){
                            cout << i << " + " << j << " = " << t << "\n";
                            return;
                        }
                    }
                }
            }
        }       

        cout << "-1\n";

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