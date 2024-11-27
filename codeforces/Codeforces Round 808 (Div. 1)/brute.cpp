

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

void get(vector<int>& a){

  while(a.size() > 1){
  	vector<int> b(a.size() - 1);
  	for(int i = 0; i < a.size() - 1; i++){
  		b[i] = a[i + 1] - a[i];
  	}
  	sort(all(b));
  	a = b;
  }

  cout << a[0] << "\n";

}

void solve() {
  int n = rng() % 10 + 5;

  vector<int> a(n);
  a[0] = 5;
  for(int i = 1; i < n; i++){
  	a[i] = 5;
  }
  sort(all(a));

  for(int i = 1; i <= n; i++){
  	vector<int> temp;
  	for(int j = 0; j < i; j++){
  		temp.push_back(a[j]);
  	}
  	debug(temp);
  	get(temp);
  }

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