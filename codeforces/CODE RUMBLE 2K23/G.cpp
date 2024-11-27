#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void __print(int x) { cerr << x; } void __print(unsigned x) { cerr << x; } void __print(float x) { cerr << x; } void __print(double x) { cerr << x; } void __print(long double x) { cerr << x; } void __print(char x) { cerr << '\'' << x << '\''; } void __print(const char* x) { cerr << '\"' << x << '\"'; } void __print(const string& x) { cerr << '\"' << x << '\"'; } void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template <typename T> void __print(const T& x) { int f = 0; cerr << '{'; for (auto& i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int M = 1e9 + 7;
int mul(int a, int b) { return ((a % M) * (b % M)) % M; }int madd(int a, int b) { return (a % M + b % M) % M; }
int mpow(int a, int b) { int pow = a, res = 1; while (b) { if (b & 1)res = mul(res, pow);pow = mul(pow, pow);b >>= 1; }return res; }
int minv(int a) { return mpow(a, M - 2); }int mdiv(int a, int b) { return mul(a, minv(b)); }int msub(int a, int b) { return (a % M - b % M + M) % M; }
void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int m=0;
        for(int j=0;j<n;j++){
            m+=a[i]<=a[j]?a[i]:0;
        }
        ans=max(ans,m);
    }
    cout<<ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin >> t; for(int i = 0;i < t; i++ ) { solve(); cout << "\n";}
    return 0;
}