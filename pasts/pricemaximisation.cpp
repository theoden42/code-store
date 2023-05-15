
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; ++i){
    	cin >> ele[i];
    }
    vector<pair<int,int>> prs(n);
    for(int i = 0; i < n; i++){
    	prs[i].first = ele[i] % k;
    	prs[i].second = ele[i];
    }
    sort(prs.begin(), prs.end());
    // for(auto& x : prs){
    // 	cout << x.first << "," << x.second << " ";
    // }
    // cout << "\n";
    int i = 0;
    int j = n - 1;
    ll sum = 0;
    while(i < j){
    	// cout << i << " " << j << "\n";
    	if(prs[i].first + prs[j].first >= k){
 			sum += (prs[i].second + prs[j].second) / k;
 			i++;
 			j--;
    	}
    	else{
    		sum += (prs[i].second + prs[i + 1].second) / k;
    		i += 2;
    	}
    	// cout << sum << "\n";
    }
    cout << sum << "\n";

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