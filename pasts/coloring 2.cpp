
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ele(m);
    for(int i = 0; i < m; i++){
    	cin >> ele[i];
    }
    int f = 0;
    int val = n / k;

	sort(all(ele));

	int count = 0;
	for(int i = 0; i < m; i++){
		if(ele[i] <= val){
			continue;
		}
		else if(ele[i] == val + 1){
			count++;
		}
		else{
			cout << "NO\n";
			return;
		}
	}

	if(count <= n % k)
		cout << "YES\n";
	else{
		cout << "NO\n";
		return;
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