

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
    vector<int> lastpos(26, -1);
    vector<int> taken;

    string ans = "";
    int prev = 0;

    for(int i = 1; i <= n; i++){
    	cout << "? 2 1 " << i << endl;
    	int x;
    	cin >> x;
    	if(x == prev + 1){
    		cout << "? 1 " << i << endl;
    		char ch;
    		cin >> ch;

    		if(ch == 1){
    			exit(0);
    		}

    		ans += ch;
    		taken.push_back(ch - 'a');
    		lastpos[ch - 'a'] = i;
    	}
    	else{
    		vector<pair<int,int>> srtvals;
    		for(auto x: taken){
    			srtvals.emplace_back(lastpos[x], x);
    		}
    		sort(all(srtvals));
    		int tsz = srtvals.size();
    		int l = 0;
    		int u = tsz - 1;
    		int ind = -1;
    		while(l <= u){
    			int mid = (l + u) / 2;
    			cout << "? 2 " << srtvals[mid].first << " " << i << endl;
    			int temp;
    			cin >> temp;
    			if(temp == tsz - mid){
    				ind = srtvals[mid].second;
    				l = mid + 1;
    			}
    			else{
    				u = mid - 1;
    			}
    		}

    		ans += (char)('a' + ind);
    		lastpos[ind] = i;
    	}
    	prev = x;
    }


    cout << "! " << ans << "\n";
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