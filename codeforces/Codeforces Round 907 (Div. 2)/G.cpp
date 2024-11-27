#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef YASH_PC
#include <debug.h>
#else
#define debug(x...)
#endif

template <typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;

#define YES cout << "YES" \
                 << "\n"
#define NO cout << "NO" \
                << "\n"
#define endl "\n"
#define pb push_back
#define int long long
const int M = 1e9 + 7;
#define all(a) a.begin(), a.end()

int mpow(int a, int b)
{
    int pow = a, res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * pow) % M;
        pow = (pow * pow) % M;
        b >>= 1;
    }
    return res;
}
int mul(int a, int b)
{
    return ((a % M) * (b % M)) % M;
}
int minv(int a) { return mpow(a, M - 2); }
int mdiv(int a, int b) { return mul(a, minv(b)); }
int madd(int a, int b) { return (a % M + b % M) % M; }
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> zidx;
    vector<int> oidx;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zidx.pb(i);
        else
            oidx.pb(i);
    }
    bool check = true;
    for (int i = 0; i < (int)oidx.size() - 1; i++)
    {
        if ((oidx[i + 1] - oidx[i]) % 2 == 0)
        {
            check = false;
        }
    }
    if (oidx.size() == 1)
    {
        if (oidx[0] % 2 == 0 && (n - oidx[0]) % 2 != 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    else
    {
        if (check)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    check = true;
    for (int i = 0; i < (int)zidx.size() - 1; i++)
    {
        if ((zidx[i + 1] - zidx[i]) % 2 == 0)
        {
            // cout << zidx[i + 1] - zidx[i] << endl;
            check = false;
        }
    }
    if (zidx.size() == 1)
    {
        if (zidx[0] % 2 == 0 && (n - zidx[0]) % 2 != 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    else
    {
        if (check)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}