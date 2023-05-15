
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
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> a(n);
    vector<int> b(n);
    map<int,vector<int>> mp;
    set<int> vals;
    for(int i = 0; i < n; i++){
    	mp[ele[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
    	if(mp[i].size() > 2){
    		cout << "NO\n";
    		return;
    	}
    	if(mp[i].size() == 0){
    		vals.insert(i);
    	}
    	else if(mp[i].size() == 1){
    		int ind = mp[i][0];
    		a[ind] = i;
    		b[ind] = i;
    	}
    	else{
    		if(vals.empty()){
    			cout << "NO\n";
    			return;
    		}
    		int ind1 = mp[i][0];
    		int ind2 = mp[i][1];
    		int val = *vals.begin();
    		vals.erase(vals.begin());
    		a[ind1] = i;
    		b[ind1] = val;
    		a[ind2] = val;
    		b[ind2] = i;
    	}
    }
    cout << "YES\n";
    for(auto& x: a){
    	cout << x << " ";
    }
    cout << "\n";
    for(auto& x: b){
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