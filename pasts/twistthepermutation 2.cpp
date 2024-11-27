
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
	int n;
	cin >> n;
	vector<int> ele(n, 0);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}
	vector<int> ans;
	for(int i = n; i >= 1; i--){
		int index = -1;
		for(int j = 0; j < i; j++){
			if(ele[j] == i){
				index = j;
				break;
			}
		}
		debug(i, index);
		if(index == i - 1){
			ans.push_back(0);
		}
		else{
			vector<int> temp(n, 0);
			for(int j = n - 1; j > i - 1; j--){
				temp[j] = ele[j];
			}
			int len = i;
			ans.push_back(index + 1);
			int mv = index + 1;
			for(int j = 0; j <= i - 1; j++){
				temp[(j - mv + len) % len] = ele[j];
			}
			ele = temp;
		}
	}
	debug(ele);
	reverse(all(ans));
	for(auto& x: ans){
		cout << x << " ";
	}
	cout << "\n";
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