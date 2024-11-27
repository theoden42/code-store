/**
 *    author:  tourist
 *    created: 27.07.2024 08:13:24
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
  vector<array<int, 3>> a(q);
  for (int i = 0; i < q; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    --l;
    a[i] = {c, l, r};
  }
  sort(a.begin(), a.end());
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    s.emplace(i, i + 1);
  }
  int64_t ans = 0;
  for (auto& [c, l, r] : a) {
    ans += c;
    auto it = prev(s.lower_bound({l + 1, -1}));
    auto seg = *it;
    it = s.erase(it);
    while (it != s.end() && it->first < r) {
      seg.second = it->second;
      ans += c;
      it = s.erase(it);
    }
    s.insert(seg);
  }
  cout << (s.size() == 1 ? ans : -1) << '\n';
  return 0;
}
