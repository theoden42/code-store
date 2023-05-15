
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
    vector<string> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }

    vector<int> bimap(n);
    vector<vector<int>> indx(26);

    for(int i = 0; i < n; i++){
    	vector<int> freq(26, 0);
    	for(int j = 0; j < v[i].size(); j++){
    		freq[v[i][j] - 'a']++;
    	}


    	int mask = 0;
    	for(int j = 0; j <= 25; j++){
    		if(freq[j] & 1){
    			mask |= (1 << j);
    		}
    	}
    	bimap[i] = mask;

    	for(int j = 0; j <= 25; j++){
    		if(freq[j] == 0){
    			indx[j].push_back(i);
    		}
    	}
    }



    ll count = 0;

    for(int i = 0; i < 26; i++){
    	int mask = (1 << 26) - 1;
    	mask ^= (1 << i);
    	map<int,int> mp;

    	for(auto ind : indx[i]){
    		int req = (mask ^ bimap[ind]);
    		count += mp[req];
    		mp[bimap[ind]] += 1;
    	}
    }	

    cout << count << "\n";
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