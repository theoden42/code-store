
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

int n;

void solve() {
	cin >> n;
	vector<vector<double>> cos(n, vector<double>(n, 0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> cos[i][j];
		}
	}

	int sz = (1 << n);
	vector<double> dp(sz, 0);
	dp[sz - 1] = 1;

	for(int i = sz - 1; i >= 0; i--){
		int temp = i;
		vector<int> sets;
		for(int j = 0; j < n; j++){
			int bit = (temp & 1);
			if(bit)sets.push_back(j);
			temp >>= 1;
		}

		temp = i;
		if(sets.size() == 0 || sets.size() == 1)continue;

		double prob = 2.0 / (sets.size() * (sets.size() - 1));


		for(int j = 0; j < sets.size(); j++){
			double sum = 0;
			for(int k = 0; k < sets.size(); k++){
				if(k == j)continue;
				sum += (prob) * (cos[sets[k]][sets[j]]);
			}
			dp[(i ^ (1 << sets[j]))] += dp[i] * sum;
		}
	}


	for(int i = 0; i < n; i++){
		cout << setprecision(10) <<  dp[1 << i] << " ";
	}

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