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
struct segtree {
    int len, maxxn = 1e18;
    vector<pair<int,int>> maxx;
    void init(int n) {
        len = 1;
        while (n > len) len *= 2;
        maxx.assign(2 * len, {-maxxn,0});
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1)
            maxx[x] = {v,i};
        else {
            int m = (lx + rx) / 2;
            if (i < m)
                set(i, v, 2 * x + 1, lx, m);
            else
                set(i, v, 2 * x + 2, m, rx);
            if(maxx[2*x+1].first>maxx[2*x+2].first){
                maxx[x]=maxx[2*x+1];
            }
            else {
                maxx[x]=maxx[2*x+2];
            }
        }
    }
    void set(int i, int v) {
        set(i, v, 0, 0, len);
    }
    pair<int,int> range(int l, int r, int x, int lx, int rx) {
        if (l >= rx or r <= lx) return {-maxxn,0};
        if (l <= lx and rx <= r) return maxx[x];
        int m = (lx + rx) / 2;
        auto a = range(l, r, 2 * x + 1, lx, m);
        auto b = range(l, r, 2 * x + 2, m, rx);
        if(a.first>b.first){
            return a;
        }
        return b;
    }
    pair<int,int> range(int l, int r) {
        return range(l, r+1, 0, 0, len);
    }
};
void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int q;cin>>q;
    segtree st;
    st.init(n);
    for(int i=0;i<n;i++){
        st.set(i,a[i]);
    }
    vector<int> prefix(n,0);
    prefix[0]=a[0];
    stack<pair<int,int>> sp;sp.push({a[0],0});
    for(int i=1;i<n;i++){
        while(sp.size()>0 and sp.top().first<=a[i])sp.pop();
        int v=0,id=-1;
        if(sp.size()>0)v=sp.top().first,id=sp.top().second;
        if(v>a[i]){
            prefix[i]=prefix[id]+(i-id)*a[i];
        }
        else {
            prefix[i]=(i+1)*a[i];
        }
        sp.push({a[i],i});
    }
    while(q--){
        int l,r;
        cin>>l>>r;l--,r--;
        auto [v,id]=st.range(l,r);int ans=0;
        if(id==r)ans=v*(r-l+1);
        else {
             ans=v*(id-l+1)+prefix[r]-prefix[id];
        }
        cout<<ans<< " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    solve();
    return 0;
}