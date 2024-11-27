
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


int check(int k, vector<int>& ele){
	int n = ele.size();
	vector<int> temp = ele;
	for(int i = 0; i < n; i++){
		if(ele[i] == -1){
			temp[i] = k;
		}
	}
	int mx = 0;
	for(int i = 1; i < n; i++){
		mx = max(mx, abs(temp[i] - temp[i - 1]));
	}
	return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int mn = 1e9 + 5;
    int l = 0; 
    int u = 1e9;
    int val = 1e9;
    while(l <= u){
    	int mid = l + (u - l)/2;
    	int x = check(mid, ele);
    	if(x <= mn){
    		mn = x;
    		val = mid;
    	}
    	if(check(mid, ele) <= check(mid + 1, ele)){
    		u = mid - 1;
    	}
    	else if(check(mid, ele) < check(mid - 1, ele)){
    		l = mid + 1;
    	}
    	else{
    		l = mid + 1;
    	}
    }
    for(int i = 0; i < n; i++){
    	if(ele[i] == -1){
    		ele[i] = val;
    	}
    }
    int m = 0;
    for(int i = 1; i < n; i++){
    	m = max(m, abs(ele[i] - ele[i - 1]));
    }

    cout << mn << " " << val << "\n";

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