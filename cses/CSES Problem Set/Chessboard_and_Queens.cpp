

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

bool check(int i, int j, vector<vector<int>>& Qn){
	int flag = 0;
	for(int a = 0; a < 8; a++){
		if(Qn[a][j] ==  1){
			flag = 1;
			return false;
		}
	}
	for(int a = 0; a < 8; a++){
		if(Qn[i][a] == 1){
			return false;
		}
	}

	int a = i;
	int b = j;
	while(a >= 0 && a < 8 && b >= 0 && b < 8){
		if(Qn[a][b])return false;
		a += 1;
		b += 1;
	}
	a = i;
	b = j;
	while(a >= 0 && a < 8 && b >= 0 && b < 8){
		if(Qn[a][b])return false;
		a += -1;
		b += 1;
	}
	a = i;
	b = j;
	while(a >= 0 && a < 8 && b >= 0 && b < 8){
		if(Qn[a][b])return false;
		a += 1;
		b += -1;
	}
	a = i;
	b = j;
	while(a >= 0 && a < 8 && b >= 0 && b < 8){
		if(Qn[a][b])return false;
		a += -1;
		b += -1;
	}

	return true;

}

int numways(int placed, vector<vector<char>>& g, vector<vector<int>>& Qn){
	if(placed >= 8)return 1;

	int count = 0;
	for(int i = placed; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(g[i][j] != '*' && check(i, j, Qn)){
				Qn[i][j] = 1;
				count += numways(placed + 1, g, Qn);
				Qn[i][j] = 0;
			}
		}
	}

	return count;
}

void solve() {
    vector<vector<char>> g(8, vector<char>(8));
    for(int i = 0; i < 8; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < 8; j++){
    		g[i][j] = s[j];
    	}
    }
    vector<vector<int>> Qn(8, vector<int>(8, 0));
    cout << numways(0, g, Qn) << "\n";

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