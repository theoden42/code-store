
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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> ac(k);
    map<int,int> mp;
    for(int i = 0; i < k; i++){
    	int x;
    	cin >> x;
    	x--;
    	ac[i].first = x;
    	mp[x]++;
    }
    for(int i = 0; i < k; i++){
    	int x;
    	cin >> x;
    	ac[i].second = x;
    }


    vector<int> temp(n, -1);
    for(auto& x: ac){
    	temp[x.first] = x.second;
    }

    vector<int> add(n, 0);
    vector<int> sub(n, 0);

    for(int i = 0; i < n; i++){
    	if(temp[i] != -1){
    		add[i] = temp[i] + i;
    		sub[i] = temp[i] - i;
    	}
    }

    debug(temp, add, sub);

    vector<int> ans(n, 1e9 + 1e8);

    set<int> t;
    for(int i = 0; i < n; i++){
    	if(temp[i] != -1){
    		t.insert(sub[i]);
    	}
    	int mn = 1e9 + 1e8;
    	if(!t.empty()){
    		mn = *t.begin();
    	}
    	ans[i] = min(ans[i], mn + i);
    }

    debug(ans);
    t.clear();

    for(int j = n - 1; j >= 0; j--){
    	if(temp[j] != -1){
			t.insert(add[j]);	
    	}
    	int mn = 1e9 + 1e8;
    	if(!t.empty())
    		mn = *t.begin();
    	ans[j] = min(ans[j], mn - j);
    }


    for(auto& x: ans){
    	cout << x << " ";
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