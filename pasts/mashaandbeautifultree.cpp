
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
	int m;
	cin >> m;
	vector<int> ele(m, 0);
	int c = 0;
	for(int i = 0; i < m; i++){
		cin >> ele[i];
	}
	for(int i = 1; i <= m; i *= 2){
		debug(ele);
		for(int j = 0; j + i < m; j += 2 * (i)){

			if(abs(ele[j] - ele[j + i]) != i){
				cout << "-1" << "\n";
				return;
			}	
			else{
				if(ele[j] < ele[j + i]){
					continue;
				}
				else{
					c++;
					debug(j);
					for(int k = j; k < j + i; k++){
						int t = ele[k];
						ele[k] = ele[k + i];
						ele[k + i] = t;
					}
				}
			}
		}
	}
	cout << c << "\n";
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