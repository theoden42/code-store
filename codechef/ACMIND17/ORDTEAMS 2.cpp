
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	vector<pair<int,pair<int,int>>> sk(3);
	for(int i = 0; i < 3; i++){
		int a, b, c;
		cin >> a >> b >> c;
		sk[i] = {a, {b, c}};
	}
	sort(all(sk));

	for(int i = 1; i < 3; i++){
		int a1 = sk[i].first;
		int a2 = sk[i - 1].first;
		int b1 = sk[i].second.first;
		int b2 = sk[i - 1].second.first;
		int c1 = sk[i].second.second;
		int c2 = sk[i - 1].second.second;
		if(a1 >= a2 && b1 >= b2 && c1 >= c2){
			if(a1 - a2 + b1 - b2 + c1 - c2 > 0){
				continue;
			}
			cout << "no\n";
			return;
		}
		cout << "no\n";
		return;
	}
	cout << "yes\n";
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