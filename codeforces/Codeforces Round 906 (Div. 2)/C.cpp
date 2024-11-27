

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

void get(int i, int j, string& s, vector<int>& ans){
	if(i >= j || ans.size() >= 300){
		return;
	}
	// debug(i, j, s);
	if(s[i] != s[j]){
		return get(i + 1, j - 1, s, ans);
	} else if(s[i] == '0'){
		string t = "";
		ans.push_back(j + 1);
		for(int k = 0; k <= j; k++){
			t += s[k];
		}
		t += "01";
		for(int k = j + 1; k < s.size(); k++){
			t += s[k];
		}
		s = t;
		return get(i + 1, j + 1, s, ans);
	} else {
		string t = "";
		ans.push_back(i);
		for(int k = 0; k < i; k++){
			t += s[k];
		}
		t += "01";
		for(int k = i; k < s.size(); k++){
			t += s[k];
		}
		s = t;
		return get(i + 1, j + 1, s, ans);
	}
}


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int i = 0;
    int j = n - 1;
    vector<int> front, back;
	if(n & 1){
		cout << "-1\n";
		return;
	}
	
	vector<int> ans;
	get(0, n - 1, s, ans);

	int f = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == s[s.size() - 1 - i]){
			f = 0;
			break;
		}
	}
	if(f){
		cout << ans.size() << "\n";
		for(auto ind: ans){
			cout << ind << " ";
		}
		cout << "\n";
	} else {
		cout << "-1\n";
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