
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
    vector<int> temp = ele;
    sort(all(temp));
    int flag = 0;
    for(int i = 0; i < n; i++){
    	if(temp[i] != ele[i]){
    		flag = 1;
    		break;
    	}
    }
    if(flag == 0){
    	cout << 0 << "\n";
    	return;
    }
    else{
    	if(temp[0] != ele[0] && temp[n - 1] != ele[n - 1]){
    		if(ele[0] == temp[n - 1] && ele[n - 1] == temp[0]){
                cout << 3 << "\n";
            }    	
            else{
                cout << 2 << "\n";
            }
        }
    	else{
    		cout << "1" << "\n";
    	}
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