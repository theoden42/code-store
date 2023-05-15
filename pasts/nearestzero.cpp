
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    sort(all(ele));
    int minall = abs(ele[n - 1] + ele[0]);


    for(int i = 0; i < n; i++){
    	int target = -1 * ele[i];
    	int l = 0;
    	int u = n - 1;
    	int mn;
    	int ind = 0;

    	if(i == 0){
    		mn = abs(ele[i + 1] - target);
    		ind = i + 1;

    	}
    	else{
    		mn = abs(ele[i] - target);
    		ind = i - 1;
    	}

    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		if(mid == i){
    			u -= 1;
    			continue;
    		}
    		if(ele[mid] == target){
    			cout << 0 << "\n";
    			return;
    		}
    		else if(target > ele[mid]){
    			if(abs(target - ele[mid]) < mn){
    				mn = abs(target - ele[mid]);
    				ind = mid;
    			}
    			l = mid + 1;
    		}
    		else{
    			if(abs(target - ele[mid]) < mn){
					mn = abs(target - ele[mid]);
					ind = mid;
    			}
    			u = mid - 1;
    		}

    	}
    	minall = min(minall, abs(ele[i] + ele[ind]));
    }
    cout << minall << "\n";
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