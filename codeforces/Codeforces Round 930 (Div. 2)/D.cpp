

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
    string s;
    cin >> s;

    vector<int> lcount(n + 1);
    vector<int> rcount(n + 2);
    vector<int> lsum(n + 1);
    vector<int> rsum(n + 2);

    for(int i = 1; i <= n; i++){
    	lcount[i] = lcount[i - 1];
    	lsum[i] = lsum[i - 1];
    	if(s[i - 1] == '>'){
    		lcount[i] += 1;
    		lsum[i] += i;
    	}
    }
    for(int i = n; i >= 1; i--){
    	rcount[i] = rcount[i + 1];
    	rsum[i] = rsum[i + 1];
    	if(s[i - 1] == '<'){
    		rcount[i] += 1;
    		rsum[i] += i;
    	}
    }

    ordset<int> left, right;
    for(int i = 0; i < n; i++){
        if(s[i] == '<')
    	   right.insert(i + 1);
    }

    for(int i = 1; i <= n; i++){
    	if(right.find(i) != right.end())
    		right.erase(i);

    	int lstop = lcount[i - 1];
    	int rstop = rcount[i + 1];
    	int ldel = 0, rdel = 0;

    	if(lstop <= rstop && s[i - 1] == '<'){
   			ldel = lstop;
   			rdel = lstop;
    	} else if(lstop > rstop && s[i - 1] == '<'){
    		ldel = rstop + 1;
    		rdel = rstop;
    	} else if(lstop <= rstop && s[i - 1] == '>'){
    		rdel = min(rstop, lstop + 1);
    		ldel = lstop;
    	} else {
    		ldel = rstop;
    		rdel = rstop;
    	}


    	int lind = (ldel == 0 ? i: *left.find_by_order(left.size() - ldel));
    	int rind = (rdel == 0 ? i: *right.find_by_order(rdel - 1));


    	int leftsum = lsum[i - 1] - lsum[lind - 1];
    	int rightsum = rsum[i + 1] - rsum[rind + 1];

    	int left_time = 2 * (ldel * i - leftsum);
    	int right_time = 2 * (rightsum - rdel * i);

    	int ans = 0;

    	int count = ldel + rdel;
    	if(count & 1){
    		if(s[i - 1] == '<')
    			ans += (n + 1 - i);
    		else 
    			ans += i;
    	} else {
    		if(s[i - 1] == '>')
    			ans += (n + 1 - i);
    		else 
    			ans += i;
    	}

    	ans += left_time;
    	ans += right_time;
    	cout << ans << " \n"[i == n];

        if(s[i - 1] == '>')
            left.insert(i);
    }
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