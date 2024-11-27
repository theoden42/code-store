#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define M 1000000007
#define set_bits __builtin_popcountll;
#define all(vp) vp.begin(), vp.end()
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <class T>
void read(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#define debug(x...)       \
    cerr << #x << " = ["; \
    _print(x)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}

//---------------xx-----------------xx----------------------xx--------------------------xx-------------------------xx----------------------------xx---------------------------------xx//


void solve()
{

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vp;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        vp.push_back(make_pair(a, b));
    }
    sort(all(vp));
    // debug(vp);
    vector<ll>temp;
    vector<ll>temp0;
    for(ll i=0;i<m;i++)
    {
        temp.push_back(vp[i].second);
    }
    for(ll i=0;i<m;i++)
    {
        temp0.push_back(vp[i].first);
    }
    // debug(temp);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {   
        ll lb;
        auto lbti=lower_bound(temp0.begin(),temp0.end(),i);
        int lbt;
        if(lbti!=temp0.end())
        {
            lbt=lbti-temp0.begin();
        }
        // else
        // {
        //     lbt=m;
        //redundant as lbti milega hi milega
        // }
        
    // debug(lbt);
        auto lbi=upper_bound(temp.begin()+lbt,temp.end(),i);
        
        if(lbi!=temp.end())
        {
            lb=*lbi-1;
        }
        else
        {
            lb=n;
        }

        
        // debug(lb);
        ll x=lb-i+1;
        // ll y=x*(x+1)/2;
        
        // debug(i,x);
        if(lbti==temp0.end())
        {
            x=n-i+1;
        }
        ans+=x;
        // debug(ans);

    }
    cout<<ans;
    // sort(all(vp));
    // debug(vp);

    /*
    min ans=n
    from 1 to 2 to 3 to 4 to 5
    if(1 to 4 ke bich any beef by any one then whole discarded )
 hame matlab b se of every pair we will see least b


    */
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // solve();
    int q;
    cin >> q;

    for (int testcase = 1; testcase <= q; testcase++)
    {

        //  cout << "Case #" << testcase << ": ";
        solve();

        cout << endl;
    }

    return 0;
}
