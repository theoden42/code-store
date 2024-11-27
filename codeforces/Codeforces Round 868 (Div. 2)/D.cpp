

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
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    vector<int> c(k);
    for(int i = 0; i < k; i++){
    	cin >> x[i];
    }
    for(int i = 0; i < k; i++){
    	cin >> c[i];
    }

    string temp = "";
    if(x[0] < c[0]){
    	cout << "NO\n";
    	return;
    }
    int f = 0;
    for(int i = 1; i < k; i++){
    	if(x[i] - x[i - 1] < c[i] - c[i - 1]){
    		f = 1;
    		break;
    	}
    }
    if(f){
    	cout << "NO\n";
    	return;
    }

	char ch = 'd';
	string buff = "abc";
	int ind = 0;

	for(int i = 1; i <= c[0] - 3; i++){
		temp += ch;
	}
	ch = (char)(ch + 1);

	for(int i = 1; i <= x[0] - c[0] + 3; i++){
		temp += buff[ind];
		ind = (ind + 1) % 3;
	}

	for(int i = 1; i < k; i++){
		int charcount = x[i] - x[i - 1];
		int palindromecount = c[i] - c[i - 1];

		for(int j = 1; j <= charcount; j++){
			if(j <= palindromecount){
				temp += ch;
			}
			else{
				temp += buff[ind];
				ind = (ind + 1) % 3;
			}
		}
		ch = (char)(ch + 1);
	}

	cout << "YES\n";
	cout << temp << "\n";
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