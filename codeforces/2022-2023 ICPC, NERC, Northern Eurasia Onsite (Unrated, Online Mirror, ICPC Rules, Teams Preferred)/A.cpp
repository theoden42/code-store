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

vector<int> random_permutation(int n){
    vector<int> temp(n);
    for(int i = 1; i <= n; i++){
        temp[i - 1] = i;
    }
    shuffle(temp.begin(), temp.end(), rng);
    return temp;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> relation(n + 1);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	relation[a[i]] = i + 1;
    }

    vector<int> p(n + 1), q(n + 1);


    for(int i = 1; i <= 100; i++){
		vector<int> r = random_permutation(n);

		int f = 1;
		for(int j = 1; j <= n; j++){
			if(r[j - 1] == j || r[j - 1] == relation[j]){
				f = 0;
				break;
			}
		}

		if(f){
			for(int j = 1; j <= n; j++){
				q[j] = r[j - 1];
				p[r[j - 1]] = relation[j];
			}
		}
    }


    for(int i = 1; i <= n; i++){
    	if(p[i] == 0 || q[i] == 0){
    		cout << "Impossible\n";
    		return;
    	}
    }

    cout << "Possible\n";
    for(int i = 1; i <= n; i++){
    	cout << p[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++){
    	cout << q[i] << " ";
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