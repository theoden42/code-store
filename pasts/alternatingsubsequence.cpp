
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
    stack<int> st;
    for(int i = 0; i < n; i++){
    	if(st.empty()){
    		st.push(ele[i]);
    	}
    	else{
    		if(ele[i] > 0 && st.top() < 0){
    			st.push(ele[i]);
    		}
    		else if(ele[i] < 0 && st.top() > 0){
    			st.push(ele[i]);
    		}
    		else {
    			if(st.top() < ele[i]){
    				st.pop();
    				st.push(ele[i]);
    			}
    		}
    	}
    }
    ll sum = 0;
    while(!st.empty()){
    	sum += st.top();
    	st.pop();
    }
    cout << sum;
    cout << "\n";

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