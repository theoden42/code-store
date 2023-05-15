
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    sort(all(ele));
    debug(ele);
    int count = 1;
    int x = ele[0];
    int index = 0;
    while(index < n){
    	int t = x + k;
    	int l = index + 1;
    	int u = n - 1;
    	int ind = -1;
    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		if(ele[mid] >= t){
    			ind = mid;
    			u = mid - 1;
    		}
    		else{
    			l = mid + 1;
    		}
    	}
    	if(ind == -1){
    		break;
    	}
    	else{
    		index = ind;
    		x = ele[ind];
    		count++;
    	}
    }
    cout << count << "\n";
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