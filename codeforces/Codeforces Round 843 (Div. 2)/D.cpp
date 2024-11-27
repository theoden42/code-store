

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
	vector<int> temp;
	while(n != 1){
		int x = spf[n];
		temp.push_back(x);
		while(n % x == 0){
			n /= x;
		}
	}
	return temp;
}

vector<vector<int>> adj(1e6 + 5);

void solve() {
    int n;
    cin >> n;
    map<int,int> primes;
    int m = n + 1;
    vector<int> num(n);

    for(int i = 0; i < n; i++){
    	cin >> num[i];
    	vector<int> pm = factorise(num[i]);
    	for(auto x: pm){
    		if(primes[x] == 0){
    			primes[x] = m++;
    		}
    		adj[i + 1].push_back(primes[x]);
    		adj[primes[x]].push_back(i + 1);
    	}
    }

    int s, t;
    cin >> s >> t;
    vector<int> dis(n + 1 + m, INF), parent(n + 1 + m, -1), vis(n + 1 + m, 0);

    queue<int> q;
    if(s == t){
    	cout << 1 << "\n";
    	cout << s << "\n";
    }
    else{
    	q.push(s);
    	dis[s] = 0;
    	vis[s] = 1;

    	while(!q.empty()){
    		int val = q.front();
    		q.pop();
    		for(auto x: adj[val]){
    			if(!vis[x]){
    				vis[x] = 1;
    				dis[x] = dis[val] + 1;
    				parent[x] = val;
    				q.push(x);
    			}
    		}
    	}

    	if(dis[t] == INF){
    		cout << "-1\n";
    	}else{
    		cout << dis[t] / 2 + 1 << "\n";
    		int x = t;
    		vector<int> ans;
    		while(x != -1){

    			if(x <= n)
    				ans.push_back(x);

    			x = parent[x];
    		}

    		reverse(all(ans));
    		for(auto a: ans){
    			cout << a << " ";
    		}
    		cout << "\n";
    	}

    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    sieve();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}