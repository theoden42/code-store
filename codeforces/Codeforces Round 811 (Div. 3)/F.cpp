

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
    vector<int> w(3, 0);
    int sum = 0;
    for(int i = 0; i < 3; i++){
    	cin >> w[i];
    	sum += w[i];
    }

    if(sum & 1){
    	cout << "NO\n";
    	return;
    }

    vector<int> dis(3, 0);
    for(int i = 0; i < 3; i++){
    	dis[i] = sum / 2 - w[(i + 1) % 3];
    }
    vector<int> temp = dis;
    sort(all(temp));

    if(temp[0] < 0 || temp[1] < 1){
    	cout << "NO\n";
    	return;
    }

    vector<pair<int,int>> edges;
    int center;
    int count = 3;

    if(temp[0] == 0){
    	center = min_element(all(dis)) - dis.begin();
    }
    else{
    	center = count++;
    }

    for(int i = 0; i < 3; i++){
    	int before = center;
    	for(int j = 1; j <= dis[i] - 1; j++){
    		edges.push_back({before, count});
    		before = count;
    		count++;
    	}
    	if(dis[i] > 0){
    		edges.push_back({before, i});
    	}
    }

    while(count < n){
    	edges.push_back({center, count++});
    }

    if(count > n){
    	cout << "NO\n";	
    	return;	
    }

    cout << "YES\n";

    for(auto x: edges){
    	cout << x.first + 1 << " " << x.second + 1<< "\n";
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