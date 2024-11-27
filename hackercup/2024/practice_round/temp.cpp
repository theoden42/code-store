//0xarmin
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define sz(x) (ll) x.size()
#define fi first
#define se second
using ll = long long;
using ld = long double;
const int INF = 1000000000;

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef ONPC
#include "debug.h"
#else
#define deb(...) 
#endif

bool isgood(ld mid, int n, ld p) {
  ld base = 1;
  for(int i = 0; i < n; i++) {
    base *= mid;
  }
  return base < p;
}

ld nthroot(int n, ld p) {
  ld l = 0, r = 2;

  ld eps = 1e-9;

  while(r - l > eps) {
    ld mid = (l + r)/2;

    if(isgood(mid, n, p)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

void solve() {
  ll n; ld p; cin >> n >> p;  

  p /= 100.0;

  ld pnth = nthroot(n, p);

  cout << fixed << setprecision(9) << (p/pnth - p) * 100;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  for(int t = 0; t < tt; t++) {
    cout << "Case #" << t+1 << ": ";
    solve();
    cout << endl;
    #ifdef ONPC
      cerr << "__________________________" << endl;
    #endif
  }

    #ifdef ONPC
      cerr << endl << "finished in " << (double)clock() / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}

