
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
    vector<int> v(n / 2);
    set<int> st;
    for(int i = 0; i < n / 2; i++){
    	cin >> v[i];
    	st.insert(v[i]);
    }

    if(st.size() < n / 2){
    	cout << "-1\n";
    	return;
    }

    set<int> st2;
    for(int i = 1; i <= n; i++){
    	if(st.find(i) == st.end()){
    		st2.insert(i);
    	}
    }

    vector<int> ans(n + 1);
    // debug(st, st2);

    for(int i = n / 2 - 1; i >= 0; i--){
    	// debug(st2, v[i]);
    	int ind = i + 1;

    	auto it = st2.lower_bound(v[i]);


    	if(st2.empty() || it == st2.begin()){
    		cout << "-1\n";
    		return;
    	}
    	it--;

    	int x = *it;

    	// debug(x);
    	st2.erase(it);
    	ans[2 * ind] = v[i];
    	ans[2 * ind - 1] = x; 
    }

    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
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