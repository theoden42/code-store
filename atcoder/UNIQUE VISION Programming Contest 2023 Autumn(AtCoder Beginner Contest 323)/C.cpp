

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

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
    	cin >> a[i];
    }
    vector<string> s(n);
    for(int i = 0; i < n; i++) { 
    	cin >> s[i];
	}

	vector<int> scores(n);
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'o') { 
				sum += a[j];
			}
		}
		scores[i] = sum + (i + 1);
	}

	int mx_score = *max_element(all(scores));
	for(int i = 0; i < n; i++){
		vector<int> unsolved;
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'x'){
				unsolved.push_back(a[j]);
			}
		}
		sort(unsolved.rbegin(), unsolved.rend());
		int flag = 1;
		for(int j = 0; j < n; j++){
			if(j == i)
				continue;
			if(scores[j] >= scores[i]) { 
				flag = 0;
				break;
			}
		}
		if(flag){
			cout << "0\n";
			continue;
		}

		int curr = scores[i];
		int ind = 0;
		while(ind < unsolved.size() && curr <= mx_score) { 
			curr += unsolved[ind++];
		}

		cout << ind << "\n";
	}
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}