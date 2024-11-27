
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ele(n, k);
    for(int i = 0; i < n; ++i){
    	cin >> ele[i];
    }
    map<int,pair<int,int>> mp;
    for(int i = 0; i < n; i++){
    	if(mp.find(ele[i]) == mp.end()){
    		mp[ele[i]] = {i, i};
    	}
    	else{
    		mp[ele[i]].second = i;
    	}
    }
    for(int i = 1; i <= k; i++){
    	int a, b;
    	cin >> a >> b;
    	if(mp.find(a) == mp.end() || mp.find(b) == mp.end()){
    		cout << "NO" << "\n";
    	}
    	else{
    		if(mp[a].first < mp[b].second){
    			cout << "YES" << "\n";
    		}
    		else{
    			cout << "NO" << "\n";
    		}
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