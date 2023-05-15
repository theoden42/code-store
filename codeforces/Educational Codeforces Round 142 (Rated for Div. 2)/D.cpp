
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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


struct p_hash{
	const int p = 1e9 + 7;
	const ll mod_m = 100000015277;
	map<ll, ll> mp;



	ll calculate_hash(vector<int>& a){

		ll hash_value = 0;
		ll p_pow = 1;
		for(auto& x: a){
			hash_value = (hash_value + (x * p_pow) % mod_m) % mod_m;
			p_pow = (p_pow * p) % mod_m; 
		}
		return hash_value;
	}

	ll get_value(vector<int>& a){
		ll h = calculate_hash(a);
		if(mp.find(h) == mp.end()){
			return 0;
		}
		else{
			return mp[h];
		}
	}

	void set_value(vector<int>& a, int value){
		ll h = calculate_hash(a);
		mp[h] += value;
	}

};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> v[i][j];
    	}
    }


    p_hash mp;



    vector<int> indexes(m + 1, 0);
    for(int i = 0; i < n; i++){
    	vector<int> temp;
    	for(int j = 0; j < m; ++j){
    		indexes[v[i][j]] = j + 1;
    	}


       	for(int j = 1; j <= m; j++){
    		temp.push_back(indexes[j]);
    		mp.set_value(temp, 1);
    	}
    }

    for(int i = 0; i < n; i++){
    	int mx = 0;
    	vector<int> temp;
    	for(int j = 0; j < m; j++){
    		temp.push_back(v[i][j]);
    		if(mp.get_value(temp) != 0){
    			mx = j + 1;
    		}
    		else{
    			break;
    		}
    	}

    	cout << mx << " ";
    }

    cout << endl;
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