

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
	vector<int> a(n), b(n);
	int ind = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 0)
			ind = i;
	}		
	for(int i = 0; i < n - 1; i++){
		b[i] = a[(ind + i + 1) % n];
	}
	b[n - 1] = 0;
	a.assign(all(b));
    int sum = 0;

    int ans = n;
    stack<pair<int,int>> st;
    for(int i = 0; i < n - 1; i++){
        // apprend a[i] to the end of the array
        int count = 0;
        int temp = sum;
        while(!st.empty() && st.top().first > a[i]){
            count += st.top().second;
            temp -= (st.top().second) * st.top().first;
            st.pop();   
        }

        temp += (count + 1) * a[i];
        st.push({a[i], count + 1});

        debug(temp);
        ans = max(ans, temp + n);
        sum = temp;
    }

    cout << ans << "\n";
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