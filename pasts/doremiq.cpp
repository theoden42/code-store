
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
    int n, q;
    cin >> n >> q;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int l = q;
    int u = n;
    int d = 0;
    while(l <= u){
    	int mid = l + (u - l)/2;
    	int lefttemp = 0;
    	int done = 0;
    	int f = q;
    	for(int i = 0; i < n; i++){
    		if(f <= 0){
    			break;
    		}
    		if(ele[i] > f){
    			if(lefttemp < n - mid){
    				lefttemp++;
    			}
    			else{
    				f--;
    				done++;
    			}
    		}
    		else{
    			done++;
    		}
    	}
    	if(done >= mid){
    		d = done;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }
    string s = "";
    int leave = 0;
    if(q >= n){
    	d = n;
    }
    // cout << d << "\n";
    for(int i = 0; i < n; i++){
    	if(q <= 0){
    		s += '0';
    		continue;
    	}
    	if(ele[i] > q){
    		if(leave < n - d ){
    		    leave++;
    		    s += '0';
    		}
    		else{
    			q--;
    			s += '1';
    		}
    	}
    	else{
    		s += '1';
    	}
    }
    cout << s << "\n";

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