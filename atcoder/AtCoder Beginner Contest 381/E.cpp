#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
#ifdef AMAN_MAC
#include "debug.h"
#else
#define debug(...)
#endif

using namespace __gnu_pbds;using namespace std;
#define int int64_t

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
template <typename T> std::istream& operator>>(std::istream& in, std::vector<T>& vec) { for(auto &v : vec) in>>v;return in;}
template <typename T> std::ostream& operator<<(std::ostream& out,std::vector<T>& vec) { for(auto &v : vec) out<<v<<" ";return out;}
int mul(int a, int b) { return ((a % M) * (b % M)) % M; }int madd(int a, int b) { return (a % M + b % M) % M; }
int mpow(int a, int b) { int pow = a, res = 1; while (b) { if (b & 1)res = mul(res, pow);pow = mul(pow, pow);b >>= 1; }return res; }
int minv(int a) { return mpow(a, M - 2); }int mdiv(int a, int b) { return mul(a, minv(b)); }int msub(int a, int b) { return (a % M - b % M + M) % M; }
int binlog(int a,int b){ int cnt=0; while(a>=b){a/=b; cnt++; } return cnt; }
void solve() {
    int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<int> ones(n+1),twos(n+2),arr;
    for(int i=0;i<n;i++){
        if(s[i]=='1')ones[i+1]++;
        ones[i+1]+=ones[i];
        if(s[i]=='/')arr.push_back(i);
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='2')twos[i]++;
        twos[i]+=twos[i+1];
    }
    auto good=[&](int m,int l,int r){
        m = arr[m];
        return 2*min(ones[m]-ones[l],twos[m]-twos[r+1])+1;
    };
    auto findgood=[&](int idl,int idr,int a,int b){
        int l=idl,r=idr;
        while(r>l+2){
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if(good(m1,a,b)<good(m2,a,b))l=m1;
            else r=m2;
        }
        if(l==r)return good(l,a,b);
        return max({good(l,a,b),good(l+1,a,b),good(r,a,b)});
    };
    while(q--){
        int l,r;cin>>l>>r;l--,r--;
        int idl = lower_bound(arr.begin(),arr.end(),l)-arr.begin();
        int idr = upper_bound(arr.begin(),arr.end(),r)-arr.begin()-1;
        if(idl<=idr){
            cout<<findgood(idl,idr,l,r)<<"\n";
        }
        else cout<<"0\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    solve();
    return 0;
}