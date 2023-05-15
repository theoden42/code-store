

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
    string s;
    cin >> s;
    int n = s.size();
    multiset<int> st;

    int f = 1;

    for(int i = 0; i < n; i++){
    	if(s[i] == '0'){
    		f = 0;
    		break;
    	}
    }


    if(f){
    	cout << n * n << "\n";
    	return;
    }

    int c = 0;
    int ind1 = 0;
    int ind2 = n - 1;

    for(int i = 0; i < n; i++){
    	if(s[i] == '0'){
    		ind1 = i;
    		break;
    	}
    	else{
    		c++;
    	}
    }
    for(int j = n - 1; j >= 0; j--){
    	if(s[j] == '0'){
    		ind2 = j;
    		break;
    	}
    	else{
    		c++;
    	}
    }

   	st.insert(c);

    c = 0;
    for(int i = ind1; i <= ind2; i++){
    	if(s[i] == '0'){
    		st.insert(c);
    		c = 0;
    	}
    	else{
    		c++;
    	}
    }

    int x = *(--st.end());
    int y = (x + 1) / 2;

    int ans = y * (x + 1 - y);
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