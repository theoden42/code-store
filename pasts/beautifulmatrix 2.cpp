
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
	vector<vector<int>> mat(5, vector<int>(5, 0));
	int ind1 = 0;
	int ind2 = 0;

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 1){
				ind1 = i;
				ind2 = j;
			}
		}
	}
	cout << abs(ind1 - 2) + abs(ind2 - 2) << "\n";
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