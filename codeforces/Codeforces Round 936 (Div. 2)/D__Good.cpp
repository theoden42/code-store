/**
 *    author:  tourist
 *    created: 22.03.2024 10:43:24
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = -1;
    for (int bit = -1; bit <= 30; bit++) {
      int goal;
      if (bit == -1) {
        goal = x;
      } else {
        if (!(x & (1 << bit))) {
          continue;
        }
        goal = (x >> bit) - 1;
      }
      vector<int> pref(n + 1);
      for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] ^ (a[i] >> max(0, bit));
      }
      if ((pref[n] & goal) == pref[n]) {
        int cur = 0;
        for (int i = 1; i <= n; i++) {
          if ((pref[i] & goal) == pref[i]) {
            cur += 1;
          }
        }
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
