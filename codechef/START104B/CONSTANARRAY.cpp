

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<int> freq(m + 1);
    multiset<int> rem;
    for(int j = 1; j <= m; j++){
    	rem.insert(j);
    }

    multiset<int> ind;
    vector<int> b(n);
    set<int> st;
    int mxfreq = 0;
    for(int i = 0; i < n; i++){
    	if(st.empty() || st.find(a[i]) == st.end()){
    		if(mxfreq <= 1){
    			b[i] = a[i];
    			rem.erase(b[i]);
    			freq[a[i]] += 1;
    			mxfreq = max(mxfreq, freq[a[i]]);
    		} else {
    			for(int j = 1; j <= mxfreq - 1; j++){
    				auto index = *ind.begin();
    				ind.erase(ind.begin());
    				b[index] = a[i];
    			}
    			b[i] = a[i];
    			freq[a[i]] = mxfreq;
    		}
    	} else {
    		// already existing element
    		int flag = 0;
    		for(int j = i + 1; j < n; j++){
    			if(st.find(a[j]) == st.end()){
    				flag = 1;
    				break;
    			}
    		}
    		if(flag){
    			ind.insert(i);
    			continue;
    		} else {
    			// have to increase some value
    			if(mxfreq > freq[a[i]]){
    				b[i] = a[i];	
    				freq[a[i]] += 1;
    			} else {
    				int f = 0;
    				for(int j = i + 1; j < n; j++){
    					if(freq[a[j]] < mxfreq){
    						b[i] = a[j];
    						freq[a[j]] += 1;
    						f = 1;
    						break;
    					}
    				}
    				if(!f){
    					b[i] = a[i];
    					freq[a[i]] += 1;
    				}
    			}
    		}
    	}
    	mxfreq = max(mxfreq, freq[a[i]]);
    	st.insert(a[i]);
    }

    while(!ind.empty() && !rem.empty()){
    	auto val = *rem.begin();
    	rem.erase(rem.begin());
    	auto id = *ind.begin();
    	ind.erase(ind.begin());
    	b[id] = val;
    }

    for(int i = 0; i < n; i++){
    	cout << b[i] << " ";
    }
    cout << "\n";
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