
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    if(n % 2 != 0){
    	ll count = 0;
    	for(int i = 1; i < n - 1; i += 2){
    		if(ele[i] > ele[i - 1] && ele[i] > ele[i + 1]){
    			continue;
    		}
    		count += max(ele[i - 1], ele[i + 1]) - ele[i] + 1;
    	}
    	cout << count << "\n";
    }
    else{
    	if(n == 4){
    		if((ele[1] > ele[0] && ele[1] > ele[2]) || (ele[2] > ele[1] && ele[2] > ele[3])){
    			cout << 0 << "\n";
    			return;
    		}
    		else{
    			cout << min(max(ele[0], ele[2]) - ele[1] + 1, max(ele[1], ele[3]) - ele[2] + 1) << "\n";
    			return;
    		}
    	}
    	vector<ll> pref(n / 2 - 1, 0);
    	int count = 0;
    	for(int i = n - 2; i > 0; i -= 2){
    		if(ele[i] > ele[i - 1] && ele[i] > ele[i + 1]){
    			if(count == 0){
    				pref[count++] = 0;
    			}
    			else{
    				pref[count] = pref[count - 1]; 
    				count++;
    			}
    		}
    		else{
    			if(count == 0){
    				pref[count++] = max(ele[i + 1], ele[i - 1]) - ele[i] + 1;
    			}
    			else{
    				pref[count] = pref[count - 1] + max(ele[i + 1], ele[i - 1]) - ele[i] + 1;
    				count++;
    			}
    		}
    	}
    	// for(auto& x: pref){
    	// 	cout << x << " ";
    	// }
    	// cout << "\n";
    	count = 0;
    	ll m = pref[n / 2 - 2];
    	ll sum = 0;
    	for(int i = 1; i < n - 1; i += 2){
    		if(ele[i] <= ele[i - 1] || ele[i] <= ele[i + 1]){
    			sum += max(ele[i - 1], ele[i + 1]) - ele[i] + 1;
    		}	
    		ll val = sum;
    		if(count <= n / 2 - 3)
    		 	val = sum + pref[n / 2 - 3 - count];
    		m = min(m, val);
    		count++;
    	}	
    	cout << m << "\n";
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