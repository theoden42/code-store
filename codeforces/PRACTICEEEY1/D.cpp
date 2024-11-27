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

vector<int> query(int v, int n){
	cout << "? " << v << endl;
	vector<int> ans(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> ans[i];
	}
	return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v = query(1, n);
    vector<int> st, st2;
    set<pair<int,int>> edges;

    for(int i = 2; i <= n; i++){

        if(v[i] == 1){
            edges.insert({1, i});
        }
        if(v[i] & 1){
            st.push_back(i);
        }
        else {
            st2.push_back(i);
        }
    }
    if(st.size() > st2.size())
        swap(st, st2);

    for(auto node: st){
        vector<int> v = query(node, n);
        for(int i = 1; i <= n; i++){
            if(v[i] == 1){
                edges.insert({min(i, node), max(i, node)});
            }
        }
    }

    // assert(edges.size() == n - 1);
    cout << "!\n";
    for(auto [a, b]: edges){
        cout << a << " " << b << "\n";
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