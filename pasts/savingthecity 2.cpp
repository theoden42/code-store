
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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> dist;
    int flag = 0;
    int f = 0;
    int count = 0;
    int dt = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '1'){
    		if(!f) f = 1;
    		if(i == 0){
    			count++;
    			dt = 0;
    		}
    		else{
    			if(s[i - 1] != '1'){
    				count++;
    				dist.push_back(dt);
    				dt = 0;
    			}
    		}
    	}
    	else{
    		if(f == 1)
    			dt++;
    	}
    }
    // cout << count << "\n";
    // for(int i = 0; i < dist.size(); i++){
    // 	cout << dist[i] << " ";
    // }
    // cout << "\n";
    if(count == 0){
    	cout << 0 << "\n";
    	return;
    }
    ll cost = count * a;
    sort(all(dist));
    for(int i = 0; i < dist.size(); i++){
    	if(dist[i] * b < a && dist[i] != 0){
    		cost -= (a - dist[i] * b);
    	}
    }
    cout << cost << "\n";
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