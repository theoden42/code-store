

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	vector<string> s(2);
	cin >> s[0] >> s[1];	
	int time, q;
	cin >> time >> q;

	int sum = 0;
	int n = s[0].size();
	for(int i = 0; i < n; i++){
		if(s[0][i] != s[1][i]){
			sum++;
		}
	}


	int index = 0;

	vector<pair<int,int>> vp;

	for(int i = 1; i <= q; i++){

		int j = index;
		for(j = index; j < vp.size() && vp[j].first <= i; j++){
			if(s[0][vp[j].second] != s[1][vp[j].second])sum++;
		}
		index = j;
		// debug(vp, index);
		// debug(sum);
		int t;
		cin >> t;


		if(t == 1){
			int pos;b
			cin >> pos;
			pos--;
			// debug(pos, s[0][pos], s[1][pos]);
			vp.push_back({i + time, pos});
			if(s[0][pos] != s[1][pos])sum--;
		}
		else if(t == 2){
			int x1, pos1, x2, pos2;
			cin >> x1 >> pos1 >> x2 >> pos2;
			x1--;x2--;pos1--;pos2--;

			if(s[0][pos1] != s[1][pos1])sum--;
			if(s[0][pos2] != s[1][pos2])sum--;
			swap(s[x1][pos1], s[x2][pos2]);
			if(s[0][pos1] != s[1][pos1])sum++;
			if(s[0][pos2] != s[1][pos2])sum++;
		}
		else{
			if(sum == 0){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
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