#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int& x : a) {
		x = nxt() - 1;
	}
	if (k == 1) {
		for (int i = 0; i < n; ++i) {
			if (a[i] != i) {
				cout << "No\n";
				return;
			}
		}
		cout << "Yes\n";
		return;
	}
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		int v = i;
		while (!used[v]) {
			used[v] = 1;
			v = a[v];
		}
		if (used[v] == 1) {
			int cnt = 0;
			int u = v;
			do {
				++cnt;
				u = a[u];
			} while (u != v);
			if (cnt != k) {
				cout << "No\n";
				return;
			}
		}
		for (int v = i; used[v] != 2; v = a[v]) {
			used[v] = 2;
		}
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}
