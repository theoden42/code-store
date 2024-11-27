
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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		ele[i] = s[i] - '0';
	}
	vector<int> odd;
	vector<int> even;
	for(int i = 0; i < n; i++){
		if(ele[i] & 1){
			odd.push_back(ele[i]);
		}
		else{
			even.push_back(ele[i]);
		}
	}
	vector<int> ans;
	int i = 0;
	int j = 0;
	while(i < odd.size() && j < even.size()){
		if(odd[i] < even[j]){
			ans.push_back(odd[i]);
			i++;
		}
		else{
			ans.push_back(even[j]);
			j++;
		}
	}

	while(i < odd.size()){
		ans.push_back(odd[i]);
		i++;
	}

	while(j < even.size()){
		ans.push_back(even[j]);
		j++;
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	cout << endl;
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