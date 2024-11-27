

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
    string a, b;
    cin >> a >> b;
    string temp = b;
    reverse(all(temp));


    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < n; i++){
    	if(a[i] != b[i])count1++;
    	if(a[i] != temp[i])count2++;
    }	

    int a1, b1, a2, b2;

    if(count1 & 1){
    	a1 = count1;
    	b1 = count1 - 1;
    }
    else{
    	a1 = count1;
    	b1 = count1;
    }

    if(count2 & 1){
    	a2 = count2;
    	b2 = count2;
    }
    else{
    	a2 = count2;
    	b2 = count2 - 1;
    }

    a2 = max(a2, 1);
    b2 = max(b2, 1);

    int ans1 = a1 + b1;
    int ans2 = a2 + b2;
    cout << min(ans1, ans2) << "\n";

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