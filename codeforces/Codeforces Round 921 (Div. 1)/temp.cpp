

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

void closestNumbers(vector<int> numbers) {
	int mn = 2e9 + 5;
	int n = numbers.size();
	vector<pair<int,int>> vp;
	sort(numbers.begin(), numbers.end());
	for(int i = 0; i < n - 1; i++){
		int df = numbers[i + 1] - numbers[i];2
		mn = min(mn, df);
	}

	for(int i = 0; i < n - 1; i++){
		int df = numbers[i + 1] - numbers[i];
		if(df == mn){
			vp.push_back({numbers[i], numbers[i + 1]});
		}
	}

	sort(vp.begin(), vp.end());
	for(auto [a, b]: vp){
		cout << a << " " << b << "\n";
	}
}	


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
    	closestNumbers({6, 2, 4, 10});
    }
}