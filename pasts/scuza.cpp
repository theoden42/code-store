
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<ll> prefix(n, 0);

    prefix[0] = ele[0];
    for(int i = 1; i < n; i++){
    	prefix[i] = ele[i] + prefix[i - 1];
    }
    debug(prefix);

    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
    	if(vp.empty()){
    		vp.push_back({ele[i], i});
    	}
    	else{
    		auto x = vp.back();
    		if(ele[i] > x.first){
    			vp.push_back({ele[i], i});
    		}
    		else{
    			continue;
    		}
    	}
    }
    debug(vp);

    for(int i = 1; i <= q; i++){
    	int k;
    	cin >> k;
    	debug(k);
    	int index = -1;
    	int l = 0;
    	int u = (int)vp.size() - 1;
    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		debug(mid);
    		if(vp[mid].first > k){
    			index = vp[mid].second;
    			u = mid - 1;
    		}
    		else{
    			l = mid + 1;
    		}
    	}
    	if(index == 0){
    		cout << "0 ";
    	}
    	else if(index == -1){
    		cout << prefix[n - 1] << " ";
    	}
    	else{
    		debug(index);
    		cout << prefix[index - 1] << " ";
    	}
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