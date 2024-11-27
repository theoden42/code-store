#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
int n, k;
int c[N];
int cnt[N];
int a[N];
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> c[i];
	}
	R(i, n - 1, 0) {
		c[i] = min(c[i], c[i + 1]);
	}
	cin >> k;
	L(i, 1, n) {
		a[i] = 0;
	}
	int cur = 1e9 + 7;
	L(i, 1, n) {
		int ban = c[i] - c[i - 1];
		int buy = ban == 0 ? cur : min(cur, k / ban);
		a[i] = buy;
		cur = buy;
		k -= buy * ban;
	}
	L(i, 1, n) {
		cout << a[i] << ' ';
	} 
	cout << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
