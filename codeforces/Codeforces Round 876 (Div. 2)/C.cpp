

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
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    if(a[n - 1] == 1){
    	cout << "NO\n";
    	return;
    }

   	cout << "YES\n";
   	vector<int> ans;

   	for(int i = n - 1; i >= 0; i--){

   		int j = i;
   		int count = 0;
   		while(j >= 0 && a[j] == a[i]){
   			count++;
   			j--;
   		}
   		if(a[i] == 0){
   			for(int k = 1; k <= count - 1; k++){
   				ans.push_back(0);
   			}
   		}
   		else{
   			for(int k = 1; k <= count; k++){
   				ans.push_back(0);
   			}
   			ans.push_back(count);
   		}
   		i = j + 1;
   	}

    if(a[0] == 0){
        ans.push_back(0);
    }

   	for(int i = 0; i < ans.size(); i++){
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