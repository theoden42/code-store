

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
    string s;
    cin >> s;
    int n = s.size();
    if(n <= 3){
        sort(all(s));
    	do{
    		int x = stoi(s);
    		if(x % 8 == 0){
    			cout << "Yes\n";
    			return;
    		}
    	} while(next_permutation(all(s)));
    	cout << "No\n";
    	return;
    }

    vector<int> v(10);
    for(auto c: s){
    	v[c - '0'] += 1;
    }

    auto check = [&](int n){
    	vector<int> f(10);
    	while(n != 0){
    		f[n % 10] += 1;
    		n /= 10;
    	}
    	for(int i = 0; i < 10; i++){
    		if(v[i] < f[i]){
    			return false;
    		}
    	}

    	return true;
    };

    for(int i = 100; i <= 999; i++){
    	if(i % 8 == 0 && check(i)){
    		cout << "Yes\n";
    		return;
    	}
    }
    cout << "No\n";
    return;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}