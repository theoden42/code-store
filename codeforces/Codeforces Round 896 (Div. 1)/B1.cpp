

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int sum = accumulate(all(a), 0ll);
   	if(sum % n != 0){
   		cout << "NO\n";
   		return;
   	}

   	int fin = sum / n;
   	map<int,int> mp;
   	for(int i = 0; i < n; i++){
   		int x = a[i] - fin;
   		if(x == 0)
   			continue;
   		int val = abs(x);
   		int count1 = 0;
   		while(val % 2 == 0){
   			count1 += 1;
   			val /= 2;
   		}

   		if(__builtin_popcountll(val + 1) != 1){
   			cout << "NO\n";
   			return;
   		}
   		val += 1;
   		int count2 = 0;
   		while(val != 1){
   			count2 += 1;
   			val /= 2;
   		}

   		count2 += count1;
   		// 1 << count2 - 1 << count1
   		if(x < 0){
   			mp[count1] += 1;
   			mp[count2] -= 1;
   		} else{
   			mp[count2] += 1;
   			mp[count1] -= 1;
   		} 
   	}

   	// debug(mp);

   	int f = 1;
   	for(auto it: mp){
   		if(it.second != 0){
   			f = 0;
   			break;
   		}
   	}
   	if(f){
   		cout << "Yes\n";
   	} else {
   		cout << "No\n";
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