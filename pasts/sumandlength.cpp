
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
    int m, s;
    cin >> m >> s;
    if(s == 0){
    	if(m > 1){
    		cout << "-1 -1" << "\n";
    		return;
    	}
    	cout << 0 << " " << 0 << "\n";
    	return;
    }
    vector<char> smax(m, '0');
    vector<char> smin(m, '0');
    int sum = s;
    if(s > 9 * m){
    	cout << "-1 -1" << "\n";
    	return;
    }
    for(int i = 0; i < m; i++){
    	if(sum >= 9){
    		smax[i] = '9';
    		sum -= 9;
    	}
    	else{
    		smax[i] = (char)('0' + sum);
    		sum = 0;
    		break;
    	}
    }
    sum = s;
    for(int i = 0; i < m; i++){
    	if(m == i + 1){
    		smin[i] = (char)('0' + sum);
    		continue;
    	}
    	int x = sum - 9 * (m - i - 1);
    	if(x <= 0 && i == 0){
    		smin[i] = '1';
    		sum -= 1;
    	}
    	else if(x <= 0 && i != 0){
    		smin[i] = '0';
    	}
    	else{
    		smin[i] = (char)('0' + x);
    		sum -= x;
    	}
    }
    for(auto& x : smin){
    	cout << x;
    }
    cout << " ";
    for(auto& x : smax){
    	cout << x;
    }
    cout << "\n";
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