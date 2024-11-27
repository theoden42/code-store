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
#define all(x) x.begin(), x.end()
const int M = 1e9 + 7;
int mul(int a, int b) { return ((a % M) * (b % M)) % M; }int madd(int a, int b) { return (a % M + b % M) % M; }
int mpow(int a, int b) { int pow = a, res = 1; while (b) { if (b & 1)res = mul(res, pow);pow = mul(pow, pow);b >>= 1; }return res; }
int minv(int a) { return mpow(a, M - 2); }int mdiv(int a, int b) { return mul(a, minv(b)); }int msub(int a, int b) { return (a % M - b % M + M) % M; }
void solve() {
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> neg,pos;int zero=0;
    for(int i=0;i<n;i++){
        if(a[i]<0)neg.push_back(a[i]);
        else if(a[i]==0)zero++;
        else pos.push_back(a[i]);
    }
            vector<int> arr(neg.size());
            for(int i=0;i<neg.size();i++)arr[i]=-1*neg[i];
            sort(arr.begin(),arr.end());
    int l = -2e18, r = 2e18;
    function<int(int)> good = [&](int mid) { 
        int cnt=0;
        if(mid<0){
            for(int i=0;i<neg.size();i++){
                int v=(mid)/neg[i];
                int id=pos.end()-upper_bound(all(pos),v);
                cnt+=id;
            }
        }
        else if(mid==0){
            cnt+=(int)pos.size()*(int)neg.size();
        }
        else {
            cnt+=(int)pos.size()*(int)neg.size()+neg.size()*zero+pos.size()*zero + (zero * (zero - 1)) / 2;
            for(int i=0;i<pos.size();i++){
                int id=lower_bound(all(pos),(mid+pos[i]-1)/pos[i])-pos.begin()-1;
                if(id<=i)break;
                cnt+=id-i;
            }
            for(int i=0;i<arr.size();i++){
                int id=lower_bound(all(arr),(mid+arr[i]-1)/arr[i])-arr.begin()-1;
                if(id<=i)break;
                cnt+=id-i;
            }
        }
        return cnt;
    };

    int ans = 1e18;
    while(r>l+1){
        int mid=(l+r)/2;
        int cnt=good(mid);
        int cnt1=good(mid+1);
        if(cnt1<k)l=mid;
        else r=mid;
    }
    if(good(l)<k and good(l+1)>=k)cout<<l;
    else cout<<r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;  for(int i = 0;i < t; i++ ) { solve(); cout << "\n";}
    return 0;
}