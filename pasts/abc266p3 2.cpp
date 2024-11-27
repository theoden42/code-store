
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



int cross(vector<vector<int> >& A)
{

    int X1 = (A[1][0] - A[0][0]);
    int Y1 = (A[1][1] - A[0][1]);
    int X2 = (A[2][0] - A[0][0]);
    int Y2 = (A[2][1] - A[0][1]);
 

    return (X1 * Y2 - Y1 * X2);
}




void solve() {
    vector<vector<int>> cord(4, vector<int> (2, 0));
    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 2; j++){
    		cin >> cord[i][j];
    	}
    }

    int p = 0;

    for(int i = 0; i < 4; i++){
    	vector<vector<int>> points = {cord[i], cord[(i + 1) % 4], cord[(i + 2) % 4]};
    	int c = cross(points);
    	if(p == 0){
    		p = c;
    	}
    	else{
    		if(p * c < 0){
    			cout << "No" << "\n";
    			return;
    		}
    		else{
    			p = c;
    		}
    	}
    }
    cout << "Yes" << "\n";
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