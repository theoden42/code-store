
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAX_N = 1e5;



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


void dfs(int source, vector<int>& vis, vector<vector<int>>& adj){
	vis[source] = 1;
	for(auto& x: adj[source]){
		if(!vis[x]){
			dfs(x, vis, adj);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> rating(n);
	for(int i = 0; i < n; i++){
		cin >> rating[i];
	}

	map<int,int> labels;

	int c = 0;

	for(int i = 0; i < n; i++){
		int temp = rating[i];
		vector<int> prime_factors = factorise(temp);
		for(auto& x: prime_factors){
			if(labels.find(x) == labels.end()){
				labels[x] = (n + c);
				c++;
			}
		}
	}




	vector<vector<int>> adj(n + c);
	for(int i = 0; i < n; i++){
		int temp = rating[i];
		vector<int> prime_factors = factorise(temp);
		for(auto& x: prime_factors){
			adj[labels[x]].push_back(i);
			adj[i].push_back(labels[x]);
		}
	} 

	debug(adj);


	vector<int> vis(n + c, 0);
	int count = 0;

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i, vis, adj);
			count++;
		}
	}

	ll ans = 2ll * (count - 1);
	cout << ans << "\n";
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