

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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



vector<bool> is_prime(MAX_N + 1, true);
vector<ll> primes;


void sieve(){
	is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }

    for(ll i = 1; i <= MAX_N; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}



void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m));

    if(!is_prime[m]){
    	int count = 1;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			ans[i][j] = count++;
    		}
    	}
    }
    else if(!is_prime[n]){
    	int count = 1;
    	for(int j = 0; j < m; j++){
    		for(int i = 0; i < n; i++){
    			ans[i][j] = count++;
    		}
    	}
    }

    else{
    	int count = 1;
    	for(int j = 0; j < m; j++){
    		for(int i = 0; i < n; i++){
    			ans[i][j] = count++;
    		}
    	}

    	vector<vector<int>> temp(n, vector<int>(m, 0));
    	for(int i = 0; i < n; i++){
    		temp[i][m / 2] = ans[i][0];
    	}


    	int j = m / 2 + 1;
    	int k = m / 2 - 1;

    	for(int i = m - 1; i >= 1; i -= 2){

    		for(int row = 0; row < n; row++){
    			temp[row][j] = ans[row][i];
    			temp[row][k] = ans[row][i - 1];
    		}
    		j++;
    		k--;
    	}
    	ans = temp;
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cout << ans[i][j] << " ";
    	}
    	cout << "\n";
    }
    cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    sieve();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}