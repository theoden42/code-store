

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
	int h, w;
	cin >> h >> w;
	int si, sj;
	cin >> si >> sj;
	si--;sj--;
	vector<string> c(h);
	for(int i = 0; i < h; i++){
		cin >> c[i];
	}
	string x;
	cin >> x;
	int i = si;
	int j = sj;
	for(auto ch: x){
		if(ch == 'R'){
			if(j + 1 < w && c[i][j + 1] == '.'){
				j += 1;
			}
		}
		if(ch == 'L'){
			if(j - 1 >= 0 && c[i][j - 1] == '.'){
				j -= 1;
			}
		}
		if(ch == 'U'){
			if(i - 1 >= 0 && c[i - 1][j] == '.'){
				i -= 1;
			}
		}
		if(ch == 'D'){
			if(i + 1 < h && c[i + 1][j] == '.'){
				i += 1;
			}
		}
	}
	cout << i + 1 << " " << j + 1 << "\n";
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