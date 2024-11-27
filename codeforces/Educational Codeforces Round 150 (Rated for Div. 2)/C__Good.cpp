

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

#define int long long 

int values(string s){
	int n = s.size();
	int mx = 0;

	int sum = 0;
	int temp = 0;

	for (int i = n - 1; i >= 0; i--){
		mx = max(mx, 1ll * s[i]);
		// debug(s[i]);
		// debug(pow(10, 1ll * (s[i] - 'A')));
		if(s[i] < mx){
			sum -= pow(10, 1ll * (s[i] - 'A'));
		}
		else{
			sum += pow(10, 1ll * (s[i] - 'A'));
		}
		// debug(i, sum);
	}

	return sum;


}

string gen(){
	int n = 10 * (rng() % 5);

	string x = "";
	for(int i = 0; i < n / 10; i++){
		char temp = (char)('A' + (rng() % 5));
		for(int j = 0; j < 10; j++){
			x += temp;
		}
	}

	return "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBBBBBBBBBAAAAAAAAAAD";

	return x;
}

void solve() {

	string s;
	cin >> s;
	int n = s.size();
	int sum = 0;

	int ans = values(s);
	char old = 'a';
	char nw = 'a';
	int ind = -1;

	// debug(ans);

	for(int i = 0; i < n; i++){
		char ch = s[i];
		for(int j = 0; j < 5; j++){

			s[i] = (char)('A' + j);
			int x = values(s);

			if(x > ans){
				ans = x;
				ind = i;
				old = ch;
				nw = (char)('A' + j);
			}

			debug(i + 1, j + 1, x);

			s[i] = ch;

		}
	}

	cout << ans << "\n";
	cout << ind + 1<< " " << old << " " << nw << "\n"; 

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