
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
    	int l = y2 - y1;
    	pair<int,int> p1 = {x1 + l, y1};
    	pair<int,int> p2 = {x2 + l, y2};
    	cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
    }
    else if(y1 == y2){
    	int l = x2 - x1;
    	pair<int,int> p1 = {x1, y1 + l};
    	pair<int,int> p2 = {x2, y2 + l};
    	cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
    }
    else{
    	int l1 = x2 - x1;
    	int l2 = y2 - y1;
    	if(abs(l1) != abs(l2)){
    		cout << -1 << "\n";
    		return;
    	}
    	pair<int,int> p1 = {x1 + l1, y1};
    	pair<int,int> p2 = {x1, y1 + l2};
    	cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}