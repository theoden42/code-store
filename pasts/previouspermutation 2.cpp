
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
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int ind = 0;
    for(int i = n - 2; i >= 0; i--){
    	if(ele[i] > ele[i + 1]){
    		ind = i;
    		break;
    	}
    }
    set<int> st;
    st.insert(ele[ind]);
    int mx = ele[ind + 1];

    for(int i = n - 1; i > ind; i--){
    	st.insert(ele[i]);
    	if(ele[i] <= ele[ind]){
    		mx = max(mx, ele[i]);
    	}
    }
	st.erase(st.find(mx));
	for(int i = 0; i <= ind - 1; i++){
		cout << ele[i] << " ";
	}
	cout << mx << " ";

	for(auto rit = st.rbegin(); rit != st.rend(); rit++){
		cout << *rit << " ";
	}

	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}