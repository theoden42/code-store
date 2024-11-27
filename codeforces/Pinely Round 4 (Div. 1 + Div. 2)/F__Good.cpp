/**
 *    author:  tourist
 *    created: 28.07.2024 10:54:17
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
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    if (r - l > 200) {
      cout << "YES" << '\n';
      continue;
    }
    vector<int> b(a.begin() + l, a.begin() + r);
    sort(b.begin(), b.end());
    int sz = int(b.size());
    int L = -1, R = -1;
    for (int i = 0; i < sz - 2; i++) {
      if (b[i] + b[i + 1] > b[i + 2]) {
        if (L == -1) L = i;
        R = i;
      }
    }
    if (R - L >= 3) {
      cout << "YES" << '\n';
      continue;
    }
    bool found = false;
    int mn = int(2e9);
    for (int i = sz - 4; i >= 2; i--) {
      mn = min(mn, b[i + 3] - b[i + 2]);
      int me = b[i + 1] - b[i];
      if ((b[i - 1] > me && b[i - 2] > mn) || (b[i - 1] > mn && b[i - 2] > me)) {
        found = true;
        break;
      }
    }
    if (!found) {
      for (int i = sz - 4; i >= 2; i--) {
        int me = b[i + 2] - b[i];
        mn = b[i + 3] - b[i + 1];
        if ((b[i - 1] > me && b[i - 2] > mn) || (b[i - 1] > mn && b[i - 2] > me)) {
          found = true;
          break;
        }
        me = b[i + 3] - b[i];
        mn = b[i + 2] - b[i + 1];
        if ((b[i - 1] > me && b[i - 2] > mn) || (b[i - 1] > mn && b[i - 2] > me)) {
          found = true;
          break;
        }
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
  return 0;
}
