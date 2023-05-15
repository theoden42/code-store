
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
   	int r, c;
   	cin >> r >> c;
   	vector<vector<char>> grid(r, vector<char> (c, 'a'));
   	for(int i = 0; i < r; i++){
   		string s;
   		cin >> s;
   		for(int j = 0; j < c; j++){
   			grid[i][j] = s[j];
   		}
   	}
   	if(r == 1){
   		for(int i = 0; i < c; i++){
   			if(grid[0][i] == '^'){
   				cout << "Impossible" << "\n";
   				return;
   			}
   		}
   		cout << "Possible" << "\n";
   		for(int i = 0; i < c; i++){
   			cout << grid[0][i];
   		}
   		cout << "\n";
   		return;
   	}
   	if(c == 1){
   		 for(int i = 0; i < r; i++){
   			if(grid[i][0] == '^'){
   				cout << "Impossible" << "\n";
   				return;
   			}
   		}
   		cout << "Possible" << "\n";
   		for(int i = 0; i < r; i++){
   			cout << grid[i][0] << "\n";
   		}
   		return;
   	}
   	cout << "Possible" << "\n";
   	for(int i = 0; i < r; i++){
   		for(int j = 0; j < c; j++){
   			cout << "^";
   		}
   		cout << "\n";
   	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}