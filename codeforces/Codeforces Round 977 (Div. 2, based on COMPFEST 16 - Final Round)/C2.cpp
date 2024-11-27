

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
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(int i = 0; i < m; i++)
    	cin >> b[i];

   	vector<int> aparent(n + 1);
   	for(int i = 1; i < n; i++){
   		aparent[a[i]] = a[i - 1];
   	}

    vector<set<int>> index(n + 1);
    for(int i = 0; i < m; i++){
    	index[b[i]].insert(i);
    }
    int cnt = 0;
    set<pair<int,int>> st;
    for(int i = 1; i <= n; i++){
    	if(!index[i].empty()){
    		st.insert({*index[i].begin(), i});
    	}
    }

	for(auto it = prev(st.end(), 1); it != st.begin(); it--){
		if(prev(it,1)->second == aparent[it->second])
			cnt += 1;
	}	
    if(a[0] == b[0] && cnt == (int)st.size() - 1){
    	cout << "YA\n";
    } else{
    	cout << "TIDAK\n";
    }

    for(int i = 1; i <= q; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;
    	int s = b[x];
    	int t = y;

        if(s == t){
            if(a[0] == b[0] && cnt == (int)st.size() - 1){
                cout << "YA\n";
            } else {
                cout << "TIDAK\n";
            }
            continue;
        }
    	if(!index[s].empty()){
    		auto it = st.find({*index[s].begin(), s});
            assert(it != st.end());	
    		if(next(it, 1) != st.end()) {
    			if(aparent[next(it, 1)->second] == it->second){
    				cnt -= 1;
    			}
    		}
    		if(it != st.begin()){
    			if(aparent[it->second] == prev(it, 1)->second){
    				cnt -= 1;
    			}
    		}
    		it = st.erase(it);
    		if(!st.empty() && it != st.begin() && it != st.end()){
    			if(aparent[it->second] == prev(it, 1)->second)
    				cnt += 1;
    		}
    	}

    	if(!index[t].empty()){
    		auto it = st.find({*index[t].begin(), t});
    		if(next(it, 1) != st.end()){
    			if(aparent[next(it, 1)->second] == it->second){
    				cnt -= 1;
    			}
    		}
    		if(it != st.begin()){
    			if(aparent[it->second] == prev(it, 1)->second){
    				cnt -= 1;
    			}
    		}
    		it = st.erase(it);
    		if(!st.empty() && it != st.begin() && it != st.end()){
    			if(aparent[it->second] == prev(it, 1)->second)
    				cnt += 1;
    		}
    	}

    	index[s].erase(x);
    	index[t].insert(x);
    	b[x] = y;
    	if(!index[s].empty()){
    		st.insert({*index[s].begin(), s});
    		auto it = st.find({*index[s].begin(), s});
    		if(next(it, 1) != st.end() && it != st.begin() && aparent[next(it, 1)->second] == prev(it, 1)->second){
    			cnt -= 1;
    		}
    		if(next(it, 1) != st.end() && aparent[next(it, 1)->second] == it->second){
    			cnt += 1;
    		}
    		if(it != st.begin() && aparent[it->second] == prev(it, 1)->second){
    			cnt += 1;
    		}
    	}
    	if(!index[t].empty()){
    		st.insert({*index[t].begin(), t});
    		auto it = st.find({*index[t].begin(), t});
    		if(next(it, 1) != st.end() && it != st.begin() && aparent[next(it, 1)->second] == prev(it, 1)->second){
    			cnt -= 1;
    		}
    		if(next(it, 1) != st.end() && aparent[next(it, 1)->second] == it->second){
    			cnt += 1;
    		}
    		if(it != st.begin() && aparent[it->second] == prev(it, 1)->second){
    			cnt += 1;
    		}
    	}
    	if(b[0] == a[0] && cnt == (int)st.size() - 1){
    		cout << "YA\n";
    	} else {
    		cout << "TIDAK\n";
    	}
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