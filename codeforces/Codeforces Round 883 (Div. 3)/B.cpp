

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
	vector<string> b(3);
	for(int i = 0; i < 3; i++){
		cin >> b[i];
	}
	// debug(b);

	for(int i = 0; i < 3; i++){
		if(b[i][0] == '.')continue;
		int f = 1;
		for(int j = 0; j < 3; j++){
			if(b[i][j] == b[i][0])
				continue;
			else {
				f = 0;
				break;
			}
		}
		if(f){
			cout << b[i][0] << "\n";
			return;
		}
	}

	for(int j = 0; j < 3; j++){
		int f = 1;

		if(b[0][j] == '.')
			continue;

		for(int i = 0; i < 3; i++){
			if(b[i][j] == b[0][j])
				continue;
			else{
				f = 0;
				break;
			}
		}

		if(f){
			cout << b[0][j] << "\n";
			return;
		}
	}

	int i = 0; 
	int j = 0;
	int f = 1;

	while(i < 3 && j < 3){
		if(b[i][j] == b[0][0] && b[0][0] != '.');
		else{
			f = 0;
			break;
		}
		i++;
		j++;
	}
	if(f){
		cout << b[0][0] << "\n";
		return;
	}

	i = 0;
	j = 2;
	f = 1;

	while(i < 3 && j >= 0){
		if(b[i][j] == b[0][2] && b[0][2] != '.');

		else{
			f = 0;
			break;
		}
		i++;
		j--;
	}
	if(f){
		cout << b[0][2] << "\n";
		return;
	}

	cout << "DRAW\n";

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