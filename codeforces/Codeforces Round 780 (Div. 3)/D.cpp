

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = n;
    int y = n;
    int prod = 0;

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    for(int i = 0; i < n; i++){
    	if(a[i] == 0)continue;

    	int neg = 0;
    	int counttotal = 0;
    	int firstneg = -1;
    	int lastneg = 0;

    	int j = i;
    	while(j < n && a[j] != 0){
    		if(a[j] < 0){
    			neg++;
    			if(firstneg == -1)firstneg = j;
    			lastneg = j;
    		}
    		if(a[j] == 2 || a[j] == -2){
    			counttotal++;
    		}
    		j++;
    	}

    	if(neg & 1){
    		int count1 = 0;
    		int count2 = 0;
    		for(int k = i; k <= firstneg; k++){
    			if(a[k] == 2 || a[k] == -2){
    				count1++;
    			}
    		}

    		for(int k = j - 1; k >= lastneg; k--){
    			if(a[k] == 2 || a[k] == -2){
    				count2++;
    			}
    		}

    		if(counttotal - count1 > prod){
    			prod = counttotal - count1;
    			x = firstneg + 1;
    			y = j;
    		}

    		if(counttotal - count2  > prod){
    			prod = counttotal - count2;
    			x = i;
    			y = lastneg;
    		}

    	}else{
    		if(counttotal > prod){
    			prod = counttotal;
    			x = i;
    			y = j;
    		}
    	}

    	i = j - 1;
    }


    cout << x << " " << n - y << "\n";
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