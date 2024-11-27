
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    for(int k = 1; k <= n; k++){
    	multiset<int> st;

    	for(int i = 0; i < n; i++){
    		st.insert(ele[i]);
    	}

    	for(int i = 1; i <= k; i++){

    		int val = k - i + 1;
    		if(st.empty()){
    			cout << k - 1 << "\n";
    			return;
    		}

    		auto it = st.upper_bound(val);
    		if(it == st.begin()){
    			cout << k - 1 << "\n";
    			return;
    		}
    		it--;
    		st.erase(it);
    		if(st.empty()){
    			continue;
    		}
    		it = st.begin();
    		int temp = *it + val;
    		st.erase(it);
    		st.insert(temp);
    	}
    	st.clear();
    }
    cout << n << "\n";
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