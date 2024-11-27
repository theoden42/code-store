

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



vector<bool> is_prime(MAX_N + 1, true);;
vector<int> spf(MAX_N + 1);

void sieve(){
	is_prime[0] = is_prime[1] = false;
    spf[0] = 0;
    spf[1] = 1;
    
    for(int i = 2; i <= MAX_N; i++){
        spf[i] = i;
    }

    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i){
                is_prime[j] = false;
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorise(int n){
    vector<int> factors;
    while(n != 1){
        int sf = spf[n];
        factors.push_back(sf);
        while(n % sf == 0){
            n /= sf;
        }
    }
    return factors;
}

vector<vector<int>> adj(MAX_N);
vector<int> mh1(MAX_N, -1);
vector<int> mh2(MAX_N, -1);
map<int,int> mp1, mp2;

pair<int,int> dfs(int source, int parent){

	mh1[source] = -1;
	mh2[source] = -1;

	for(auto x: adj[source]){
		if(x == parent)continue;
		auto it = dfs(x, source);
		debug(it, x, source);
		mh1[source] = (it.first != -1) ? max(mh1[source], it.first + 1) : mh1[source];
		mh2[source] = (it.second != -1) ? max(mh2[source], it.second + 1) : mh2[source];
	}

	if(mp1[source] == 1){
		mh1[source] = max(mh1[source], 0);
	}
	if(mp2[source] == 1){
		mh2[source] = max(mh2[source], 0);
	}
	return {mh1[source], mh2[source]};
}

int one_get(int source, int parent){
	debug(source);

	int sum = 0;
	for(auto x: adj[source]){
		if(x == parent)continue;
		
		if(mh1[x] != -1 || mh2[x] != -1){
			sum += 2 + one_get(x, source);
		}
	}
	return sum;
}

int get(int source, int parent, int d){
	int sum = 0;
	for(auto x: adj[source]){
		if(x == parent)continue;

		int n1 = mh1[x];
		int n2 = mh2[x];

		debug(source, x, n1, n2);

		if(n1 != -1 && n2 != -1){
			sum += (4 + get(x, source, d));
		}
		else if(n1 != -1){
			if(n1 + 1 > d){
				sum += (4 + get(x, source, d));
			}
			else{
				sum += (2 + one_get(x, source));
			}
		}
		else if(n2 != -1){
			if(n2 + 1 > d){
				sum += (4 + get(x, source, d));
			}
			else{
				sum += (2 + one_get(x, source));
			}
		}
	}
	return sum;
}

void solve() {
    int n, d;
    cin >> n >> d;

    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    int m1;
    cin >> m1;
    for(int i = 0; i < m1; i++){
    	int x;
    	cin >> x;
    	mp1[x]++;
    }
    int m2;
    cin >> m2;
    for(int i = 0; i < m2; i++){
    	int x;
    	cin >> x;
    	mp2[x]++;
    }

    dfs(1, -1);

    int ans = get(1, -1, d);
    cout << ans << "\n";

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