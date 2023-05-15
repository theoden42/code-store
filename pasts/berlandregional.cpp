
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

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> st(n, {0, 0});
    for(int i = 0; i < n; i++){
    	cin >> st[i].first;
    }
    for(int i = 0; i < n; i++){
    	cin >> st[i].second;
    }

    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	mp[st[i].first].push_back(st[i].second);
    }

    for(auto& x: mp){
    	sort(x.second.rbegin(), x.second.rend());
    }

    vector<ll> strength(n + 1, 0);

    for(auto& x: mp){
    	vector<int> temp = x.second;
    	ll sum = 0;
    	for(int i = 1; i < (int)temp.size(); i++){

			sum += temp[(int)temp.size() - i];
			debug(i, sum, x.first);
    		int val = temp.size() - i;
    		debug(val);

    		for(int j = 1; j * j <= val; j++){
    			if(val % j == 0){
    				if(j > i)
    					strength[j] -= sum;
    				if(val / j > i && val / j != j)
    					strength[val / j] -= sum;
    			}
    		}
    	}
    }

    for(auto& x: mp){
    	vector<int> temp = x.second;
    	ll tmpsum = 0;
    	tmpsum = accumulate(temp.begin(), temp.end(), tmpsum);
    	for(int i = 1; i <= temp.size(); i++){
    		strength[i] += tmpsum;
    	}
    }


	for(int i = 1; i <= n; i++){
		cout << strength[i] << " ";
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