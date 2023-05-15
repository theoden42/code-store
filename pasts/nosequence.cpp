
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, k, s;
    cin >> n >> k >> s;
    int temp = s;
    vector<int> vals;
    while(temp != 0){
    	int val = temp % k;
    	vals.push_back(val);
    	temp = temp / k;
    }	


    vector<int> ans;

	for(int i = 0; i < vals.size(); i++){
		if(vals[i] == 0){
			ans.push_back(0);
		}
		else if(vals[i] == 1){
			ans.push_back(1);
		}
		else if(vals[i] == k - 1){
			ans.push_back(-1);
			int j = i + 1;
			while(j < vals.size() && (vals[j] == k - 1 || vals[j] == k - 2)){
				if(vals[j] == k - 1){
					ans.push_back(0);
				}
				else{
					ans.push_back(-1);
				}
				j++;
			}
			if(j == vals.size()){
				ans.push_back(1);
			}
			else{
				if(vals[j] == 0){
					ans.push_back(1);
				}
				else{
					debug(vals[j]);
					cout << "-2\n";
					return;
				}
			}
			i = j;
		}
		else{
			cout << "-2\n";
			return;
		}
	}
	if(ans.size() > n){
		cout << "-2\n";
		return;
	}
	int count = 0;
	for(auto& x: ans){
		cout << x << " ";
		count++;
	}
	for(int i = count + 1; i <= n; i++){
		cout << 0 << " ";
	}
	cout << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}