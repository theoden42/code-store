
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
    int y = n;
    if(n == 1){
    	cout << "FastestFinger" << "\n";
    	return;
    }
    if(n % 2 != 0){
    	cout << "Ashishgup" << "\n";

    }
    else{
    	int count = 1;
    	int temp = 0;
    	while(y % 2 == 0){
    		temp++;
    		y = y / 2;
    	}
    	for(int i = 3; i * i <= n && y > 1; i += 2){
    		if(y % i == 0){
    			temp = 0;
    			while(y % i == 0){
    				temp++;
    				y = y / i;
    			}
    			count = count * (temp + 1);
    		}
    	}
    	count = count - 1;
    	cout << count << "\n";
    	if(count % 2 == 0){
    		cout << "Ashishgup" << "\n";
    	}
    	else{
    		cout << "FastestFinger" << "\n";
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