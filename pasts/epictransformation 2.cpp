
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
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	mp[x]++;
    }
    vector<int> ele;
    for(auto& x: mp){
    	// cout << x.second << " ";
    	if(x.second != 0){
    		ele.push_back(x.second);
    	}
    }
    // cout << "\n";
    // for(auto& x: ele){
    // 	cout << x << " ";
    // }
    // cout << "\n";
    sort(ele.begin(), ele.end());
    auto it = ele.begin();
    ll sum = 0;
    while(it < ele.end() - 1){
    	sum += (*it);
    	it++;
    }
    if(sum >= *(ele.end() - 1)){
    	if(n % 2 == 0){
    		cout << '0' << "\n";
    	}
    	else{
    		cout << 1 << "\n";
    	}
    	
    }
    else{
    	cout << *(ele.end() - 1) - sum << "\n";
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