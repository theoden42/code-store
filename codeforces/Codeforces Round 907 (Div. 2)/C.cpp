
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    sort(all(a));
    int sum = 0;

    int arrsum = accumulate(all(a), 0ll);

    int i = 0;
    int j = n - 1; 
    int currsum = 0;
    while(i < j){
    	if(currsum + a[i] < a[j]){
    		currsum += a[i];
    		sum += a[i];
    		a[i] = 0;
    		i += 1;
    	} else {
    		sum += (a[j] - currsum);
    		sum += 1;
    		a[i] -= (a[j] - currsum);
     		a[j] = 0;
    		currsum = 0;
    		j -= 1;
    	}
    	debug(a, currsum, sum);
    }


    int more = a[j] + currsum;
    sum += (more / 2) - currsum;
    if(more > 1)
        sum += 1;
    sum += (more & 1);

    cout << sum << "\n";
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