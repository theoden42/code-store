d// Problem: E1. Doremy's Drying Plan (Easy Version)
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/E1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define debug(x) cout << endl << #x << ": " << x << endl
#define endl "\n"
#define PII pair<int, int>
#define PID pair<int, double>
#define PDI pair<double, int>
#define ls p << 1
#define rs (p << 1) + 1
#define pb push_back
#define ppb pop_back
#define fs first
#define sc second
#define Random(x)                       \
    mt19937_64 rnd(random_device {}()); \
    uniform_int_distribution<int> u(1, (x)-5);
using ll = long long;
using ull = unsigned long long;
using db = double;
using namespace std;
const int N = 2e5 + 10, INF = 1e9;

int n, m, k;
struct line {
    int l, r;
    bool operator<(const line that) const {
        if(that.l == l) return r < that.r;
        return l < that.l;
    }
} a[N];

void solve() {
    cin >> n >> m >> k;

    vector<int> s1(n + 2, 0), s2(n + 2, 0), s(n + 2, 0);
    vector<vector<PII>> l(n + 2, vector<PII>());
    for(int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r;
        s[a[i].l]++, s[a[i].r + 1]--;
    }

    sort(a + 1, a + 1 + m);
    for(int i = 1; i <= m; ++i) l[a[i].l].pb({a[i].r, i});

    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        s[i] += s[i - 1];
        if(s[i] == 0) sum++;
        if(s[i] == 1) s1[i] = 1;
        if(s[i] == 2) s2[i] = 1;
        s1[i] += s1[i - 1];
        s2[i] += s2[i - 1];
    }
	
    vector<int> mx, v(m + 1, 0);
    for(int i = 1; i <= m; ++i) mx.pb(s1[a[i].r] - s1[a[i].l - 1]);

	int ans = sum;
    sort(mx.begin(), mx.end());
    ans = max(ans, sum + mx.back() + *prev(prev(mx.end())));
	priority_queue<PII, vector<PII>, greater<PII>> q;
    for(int i = 1; i <= n; ++i) {
        while(q.size() && q.top().fs < i) q.pop();
        while(l[i].size()) {
            auto [r, id] = l[i].back();
            l[i].ppb();
            q.push({r, a[id].l});
        }

        if(s2[i] - s2[i - 1]) {
        	auto [r1, l1] = q.top();
        	q.pop();
        	auto [r2, l2] = q.top();
        	q.pop();
        	
        	q.push({r1, l1});
        	q.push({r2, l2});
        	
        	int t = s1[max(r1, r2)] - s1[min(l1, l2) - 1]
        			+ s2[min(r1, r2)] - s2[max(l1, l2) - 1];
        	ans = max(ans, sum + t);
        }
    }

    cout << ans << endl;
}

signed main() {
    // FAST;
    int T = 1;
    cin >> T;
    while(T--) solve();
}