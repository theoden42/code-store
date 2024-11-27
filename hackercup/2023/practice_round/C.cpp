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
    vector<int> a(2 * n - 1);
    for(int i = 0; i < 2 * n - 1; i++){
    	cin >> a[i];
    }
    sort(all(a));
    if(n == 1){
    	cout << 1 << "\n";
    	return;
    }

    int ans1 = -1;
    int i = 1;
    int j = 2 * n - 2;
    int flag = 1;
    while(i < j){
    	int initsum = a[1] + a.back();
    	int tempsum = a[i] + a[j];
    	if(tempsum != initsum){
    		flag = 0;
    		ans1 = -1;
    		break;
    	}
    	i += 1;
    	j -= 1;
    }
    if(flag){
    	ans1 = a[1] + a.back() - a[0];
        if(ans1 < 1 || ans1 < a.back()){
            ans1 = -1;
        }
    }

    int ans2 = -1;
   	i = 0;
    j = 2 * n - 2;
    flag = 1;
    while(i < j){
    	int initsum = a[0] + a.back();
    	int tempsum = a[i] + a[j];
    	if(tempsum == initsum){
    		i += 1;
    		j -= 1;
    	} else if(tempsum > initsum){
            if(flag){
                flag = 0;
                ans2 = initsum - a[j];
                j--;
            } else {
                ans2 = -1;
                break;
            }
    	} else {
    		if(flag){
    			flag = 0;
    			ans2 = initsum - a[i];
    			i++;
    		} else {
    			ans2 = -1;
    			break;
    		}
    	}
    }

    if(flag){
    	ans2 = a[0] + a.back() - a[i];
    }

    int ans3 = -1;
    i = 0;
    j = 2 * n - 3;
    flag = 1;
    while(i < j) { 
    	int initsum = a[2 * n - 3] + a[0];
    	int tempsum = a[i] + a[j];
    	if(tempsum != initsum){
    		flag = 0;
    		break;
    	}
    	i += 1;
    	j -= 1;
    }
    if(flag) { 
    	ans3 = a[2 * n - 3] + a[0] - a[2 * n - 2];
        if(ans3 < 1 || ans3 > a[0]){
            ans3 = -1;
        }
    }

    ans1 = (ans1 == -1) ? 1e18: ans1;
    ans2 = (ans2 == -1) ? 1e18: ans2;
    ans3 = (ans3 == -1) ? 1e18: ans3;

    debug(a, ans1, ans2, ans3);
    int fin = min({ans1, ans2, ans3});
    if(fin == 1e18){
    	cout << "-1\n";
    } else {
    	cout << fin << "\n";
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}