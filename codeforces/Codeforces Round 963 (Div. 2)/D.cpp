/*--------------DCODER13--------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define BITS 32
#define binary(n) bitset<BITS>(n).to_string()
#define setbits(n) bitset<BITS>(n).count()

template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//----------------------------------------------------------------------------------------------------------

vector<int> lowprime(int N);                          // returns lowest prime of all natural numbers upto N
int binexpo(int base , int power);                    //returns (base)^power

//----------------------------------------------------------------------------------------------------------

const int M=1e9 +7;
vector<int> lp=lowprime(1 + (int)1e5);
bool check(int mid, int k, vector<int>& a, int n){
    vector<int> dp(n+1, INT_MIN);
    vector<int> pre(n+1, 0);
    for (int i = 0; i < n; i++){
        pre[i+1] = pre[i]+(a[i]>=mid?-1:1);
    }
    dp[0]=0;
    for (int i = 1; i <= n; ++i){
        if(i>=k)dp[i]=max(dp[i-1], pre[i]-pre[i-k] + dp[i-k]);
        else dp[i]=dp[i-1];
    }
    // cout<<mid<<' '<<pre[n]<<" "<< dp[n]<<"\n";
    return (pre[n]-dp[n] < 0);
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a)cin>>x;
    vector<int> b=a;
    sort(all(b));
    int lo=0 , hi=n-1 , mid;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(check(b[mid], k, a, n))
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    // while(hi<n-1 and check(b[hi+1], k, a, n))hi++;
    cout<<b[hi]<<endl;

}

//----------------------------------------------------------------------------------------------------------

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--){
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------


int binexpo(int base , int power){
    int res=1;
    while(power){
        if(power&1){
            power--;
            res*=base%M;
            res%=M;
        }
        else{
            power/=2;
            base*=base%M;
            base%=M;
        }
    }
    return res;
}


vector<int> lowprime(int N){
    vector<int> lp(N+1,0) ,prime(N+1,0);
    for(int i=2; i <=N; i++){
        if(!prime[i]){
            lp[i]=i;
            for(int j=2; j<N/i+1; j++){
                prime[i*j]=1;
                if(!lp[j*i])
                    lp[i*j]=i;
            }
        }
    }
    return lp;
}