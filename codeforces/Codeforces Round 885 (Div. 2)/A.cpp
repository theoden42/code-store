

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
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;
    vector<pair<int,int>> cord(k);
    for(int i = 0; i < k; i++){
    	int a, b;
    	cin >> a >> b;
    	cord[i] = {a, b};
    }

    // if(k > 4){
    // 	cout << "NO\n";
    // 	return;
    // }
    // if(k >= min(n, m)){
    // 	cout << "NO\n";
    // 	return;
    // }

    vector<pair<int,int>> pos;
    vector<pair<int,int>> move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for(auto mv: move){
    	int nx = x + mv.first;
    	int ny = y + mv.second;
    	if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
    		pos.push_back({nx, ny});
    	}
    }

    for(auto p: pos){
    	int flag = 1;
    	for(auto f: cord){
    		int dis = abs(p.first - f.first) + abs(p.second - f.second);
    		if(dis & 1){
    			flag = 0;
    			break;
    		}
    	}
    	if(flag){
    		cout << "YES\n";
    		return;
    	}
    }
    cout << "NO\n";

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