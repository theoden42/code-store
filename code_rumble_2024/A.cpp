#include <bits/stdc++.h>
using namespace std;

int m, n;
int get_par(int node) { return (node - 1) / m; }
string lock(string s, int uid, map<string, int> &mp, vector<int> &lockable,
            vector<int> &cnt) {
  if (lockable[mp[s]] != -1)
    return "false";
  // thread safe
  compare_and_swap({lockable[node], cnt[node]}, expected = {-1, 0},
                   newValue = uid);

  int node = mp[s];
  bool flag = true;

  // Suppose thread one checks all the parent
  // Suppose that threads checks all it's parent before this node is locked.
  // so this is why race condition arises.

  // how to solve using mutexes:
  /* 1. Naive -> Mutex on whole lock function
     2. Lockable, cnt array is locked instead of lock fn
     3. Shared read lock does not work because of dirty reads in case one
     threads locks another threads ancesstors
     4. since multiple threads can access mutexes if one of them is ancesstor of
     other. 5.
  */

  while (node != 0) {
    flag &= (lockable[node] == -1);

    node = get_par(node);
  }

  flag &= (lockable[0] == -1);

  if (!flag) {
    return "false";
  }

  if (cnt[mp[s]]) {
    return "false";
  }

  lockable[mp[s]] = uid;

  node = mp[s];

  while (node != 0) {
    cnt[node]++;
    node = get_par(node);
  }

  cnt[0]++;

  return "true";
}

string unlock(string s, int uid, map<string, int> &mp, vector<int> &lockable,
              vector<int> &cnt) {
  if (lockable[mp[s]] != uid)
    return "false";

  lockable[mp[s]] = -1;

  int node = mp[s];

  while (node != 0) {
    cnt[node]--;
    node = get_par(node);
  }

  cnt[0]--;
  return "true";
}

int main() {
  int q;
  cin >> n >> m >> q;
  vector<string> names(n);
  map<string, int> mp;
  vector<int> lockable(n, -1);
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++) {

    cin >> names[i];
    mp[names[i]] = i;
  }

  while (q--) {
    int op, uid;
    string s;
    cin >> op >> s >> uid;

    if (op == 1) {
      cout << lock(s, uid, mp, lockable, cnt) << endl;
    } else {
      cout << unlock(s, uid, mp, lockable, cnt) << endl;
    }
  }
}

/*

Race conditions:
Two can lock and one lock becomes reduntant.
     1
    /  \
    2   3


*/