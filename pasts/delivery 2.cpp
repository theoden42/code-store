
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
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    sort(all(ele));
    int ind = -1;
   	for(int i = 0; i < n; i++){
   		if(ele[i] == 0){
   			ind = i;
   			break;
   		}
   	}
   	if(ind == -1){
   		n++;
   		ele.push_back(0);
   	   	sort(all(ele));
   		int ma = abs(ele[n - 1]) + abs(ele[0]);
   		// cout << ma << "\n";
   		for(int i = 0; i < n; i++){
   			if(ele[i] == 0){
   				ind = i;
   				break;
   			}
   		}
   		for(int i = 0; i <= k; i++){
   			// cout << ind + i << " " << ind - (k - i) << "..\n";
   			if(ind + i < n  && ind - (k - i) >= 0){
   				int val = abs(ele[ind + i]) + abs(ele[ind - k + i]) +   min(abs(ele[ind + i]), abs(ele[ind - k + i]));
   				ma = min(val, ma);
   			}
   			// cout << i << " " << ma << "\n";
   		}
   		cout << ma << "\n";
   	}
   	else{
   		int ma = abs(ele[n - 1]) + abs(ele[0]);
   		// cout << ma << "\n";
   		for(int i = 0; i < n; i++){
   			if(ele[i] == 0){
   				ind = i;
   				break;
   			}
   		}
   		k--;
   		for(int i = 0; i <= k; i++){
   			// cout << ind + i << " " << ind - (k - i) << "..\n";
   			if(ind + i < n  && ind - (k - i) >= 0){
   				int val = abs(ele[ind + i]) + abs(ele[ind - k + i]) +  min(abs(ele[ind + i]), abs(ele[ind - k + i]));
   				ma = min(val, ma);
   			}
   			// cout << i << " " << ma << "\n";
   		}
   		cout << ma << "\n";
   	}	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}