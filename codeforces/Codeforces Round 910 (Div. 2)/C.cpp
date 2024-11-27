

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
                                int n, m;
                                cin >> n >> m;
                                int k;
                                cin >> k;

                                int mn = (n - 1) + (m - 1);
                                if(mn > k){
                                	cout << "NO\n";
                                	return;
                                }

                                if(((k - mn) % 4) & 1){
                                    cout << "NO\n";
                                    return;
                                }

                                cout << "YES\n";
                                vector<vector<int>> hor(n, vector<int>(m - 1));
                                vector<vector<int>> vert(n - 1, vector<int>(m));

                                int val = 0;
                                for(int i = 0; i < n - 1; i++){
                                	vert[i][0] = val;
                                	val = 1 - val;
                                }
                                for(int j = 0; j < m - 1; j++){ 
                                	hor[n - 1][j] = val;
                                	val = 1 - val;
                                }


                                if(k - mn == 2){
                                    hor[n - 2][m - 2] = val;
                                    val = 1 - val;
                                    vert[n - 2][m - 1] = val;
                                    vert[n - 2][m - 2] = val;
                                } else {
                                    vert[n - 2][m - 1] = val;
                                    vert[n - 2][m - 2] = val;
                                    hor[n - 3][m - 2] = val;

                                    val = 1 - val;
                                    hor[n - 2][m - 2] = val;
                                    vert[n - 3][m - 1] = val;
                                    vert[n - 3][m - 2] = val;
                                }


                                for(int i = 0; i < n; i++){
                                	for(int j = 0; j < m - 1; j++){
                                		char c = (hor[i][j] ? 'R' : 'B');
                                		cout << c << " ";
                                	}
                                	cout << "\n";
                                }

                                for(int i = 0; i < n - 1; i++){
                                	for(int j = 0; j < m; j++){
                                		char c = (vert[i][j] ? 'R' : 'B');
                                		cout << c << " ";
                                	}
                                	cout << "\n";
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