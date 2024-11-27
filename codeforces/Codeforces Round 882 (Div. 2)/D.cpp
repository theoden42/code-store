

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

        const int MAX_N = 1e9 + 5;
        const ll MOD = 1e9 + 7;
        const ll INF = 1e8;

        void solve() {
           int n, m, q;
           cin >> n >> m >> q;
           string st;
           cin >> st;

           vector<pair<int,int>> pt(n, {INF, INF});

           int left = 0;


           set<int> indst;
           for(int i = 0; i < n; i++){
              indst.insert(i);
           }


           for(int i = 0; i < m; i++){
              int l, r;
              cin >> l >> r;
              l--;
              r--;
              auto it = indst.lower_bound(l);
              while(it != indst.end() && *it <= r){
                int ind = *(it);
                pt[ind] = {i, (ind - l)};
                indst.erase(it);
                it = indst.lower_bound(l);
              }
           }


           ordset<pair<int,int>> ones;
           ordset<pair<int,int>> zero;

           int count = INF;

           for(int i = 0; i < n; i++){
            int f = 0;
              if(pt[i].first == INF){
                f = 1;
                pt[i] = {count++, count++};
              }
              if(st[i] == '0'){
                if(!f)
                    zero.insert(pt[i]);
              }
              else{
                ones.insert(pt[i]);
              }
           }


           auto calc = [&](){
             if(ones.empty() || zero.empty())return 0;

             int low = 1;
             int high = zero.size();
             int mx = 0;

             // debug(ones, zero);

             while(low <= high){
                int mid = (low + high) / 2;
                auto x = *(zero.find_by_order(mid - 1));
                auto it = ones.order_of_key(x);
                int num = ones.size() - it;
                if(num >= mid){
                    low = mid + 1;
                    mx = mid;
                }
                else{
                    high = mid - 1;
                }
             }

             return mx;
           };


           for(int i = 1; i <= q; i++){
                int x;
                cin >> x;
                x--;

                if(st[x] == '0'){
                    if(pt[x].first < INF){  
                        zero.erase(zero.find(pt[x]));
                    }
                    ones.insert(pt[x]);
                    st[x] = '1';
                }
                else{
                    ones.erase(ones.find(pt[x]));
                    if(pt[x].first < INF){
                        zero.insert(pt[x]);
                    }
                    st[x] = '0';
                }

                int a = calc();
                cout << a << "\n";

           }
        }


        int main() {
            ios_base::sync_with_stdio(0);
            cin.tie(0); cout.tie(0);
            int tc = 1;
           // cin >> tc;
            for (int t = 1; t <= tc; t++) {
                // cout << "Case #" << t << ": ";
                solve();
            }
        }