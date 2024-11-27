

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
    char c;
    cin >> c;
    vector<string> pl(2 * n);
    map<char,vector<int>> mp;
    for(int i = 0; i < 2 * n; i++){
    	cin >> pl[i];
    	mp[pl[i][1]].push_back(pl[i][0] - '0');
    }

    vector<pair<string,string>> ans;
    vector<string> left;
    int count = 0;

    for(auto& [ch, it]: mp){
    	if(ch == c)
    		continue;
    	sort(all(it));
    	if(it.size() & 1){
    		count += 1;	
    		string s = "";
    		s += (char)('0' + it.back());
    		s += ch;
    		left.push_back(s);
    	}
    	for(int i = 0; i < it.size() - 1; i += 2){
    		string l1 = "";
    		string l2 = "";
    		l1 += ch;
    		l2 += ch;
    		l1 += (char)('0' + it[i]);
    		l2 += (char)('0' + it[i + 1]);
    		ans.push_back({l1, l2});
    	}
    }

    debug(ans);

    if(left.size() > mp[c].size()){
    	cout << "IMPOSSIBLE\n";
    } else {
    	for(auto [a, b]: ans){
    		cout << a << " " << b << "\n";
    	}
    	while(mp[c].size() > 0){
    		string x = "";
    		x += c;
    		x += (char)('0' + mp[c].back());
    		cout << left.back() << " " << x << "\n";
    		left.pop_back();
    		mp[c].pop_back();
    	}
    	for(int i = 0; i < mp[c].size() - 1; i++){
    		string l1 = "";
    		string l2 = "";
    		l1 += c;
    		l2 += c;
    		l1 += (char)('0' + mp[c][i]);
    		l2 += (char)('0' + mp[c][i + 1]);
    		cout << l1 << " " << l2 << "\n";
    	}
    }

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