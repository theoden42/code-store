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

int f(int left, int right, int bitnum, vector<int>& a, vector<int>& b){
	if(right < left){
		return (1 << 30) - 1;
	}
	if(bitnum < 0)return 0;

	int counta = 0;
	int countb = 0;

	// debug(a, b);
	for(int i = left; i <= right; i++){
		if((a[i] >> bitnum) & 1)counta++;
		if((b[i] >> bitnum) & 1)countb++;
	}
	int len = right - left + 1;


	if(counta != len - countb){
		return f(left, right, bitnum - 1, a, b);
	}
	else{
		int ind = 0;
		for(int i = left; i <= right; i++){
			if(!(a[i] >> bitnum & 1)){
				swap(a[ind], a[i]);
				ind++;
			}
		}
		ind = 0;
		for(int i = left; i <= right; i++){
			if(b[i] >> bitnum & 1){
				swap(b[ind], b[i]);
				ind++;
			}
		}
		int ans = (1 << bitnum);

		for(int i = bitnum - 1; i >= 0; i--){
			int x = f(left, left + countb - 1, i, a, b);
			int y = f(left + countb, right, i, a, b);
			ans = max(ans, (1 << (bitnum)) + (x & y));	
		}

		return ans;
	}

}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    int ans = f(0, n - 1, 29, a, b);

    cout << ans << "\n";
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