

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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;


    vector<queue<int>> q(26);
    for(int i = 0; i < m; i++){
    	q[s[i] - 'a'].push(i);
    }

    string curr = "";
    int ind = -1;
    int f = 1;
    for(int i = 0; i < n; i++){
    	int nmx = 0;
    	int charind = 0;
    	for(int j = 0; j < k; j++){
    		while(!q[j].empty() && q[j].front() <= ind){
    			q[j].pop();
    		}
    		if(q[j].empty()){
    			curr += (char)('a' + j);	
    			f = 0;
    			break;
    		} else {
    			if(q[j].front() > nmx){
    				nmx = q[j].front();
    				charind = j;
    			}
    		}
    	}	
        if(!f)
            break;
    	curr += (char)('a' + charind);
    	ind = nmx;
    }

    if(!f){
    	cout << "NO\n";
    	while(curr.size() < n){
    		curr += 'a';
    	}
    	cout << curr << "\n";
    } else {
    	cout << "YES\n";
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