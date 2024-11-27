#include <bits/stdc++.h>
#define ll long long int
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define f_0(i, n) for (ll i = n - 1; i > -1; i--)
#define f_1(i, n) for (ll i = n; i > 0; i--)
#define MOD 998244353LL
#define ALL(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define pbc pop_back
#define pll pair<ll, ll>
#define N_MAX 1000'000LL
#define INF 1000'000'000'000'000'000LL
#define MINUS_INF -1000'000'000'000'000'000LL
#define NIL 0
// #define ONLINE_JUDGE 1
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

vector<ll> inputVector(ll n)
{
    vector<ll> input(n);
    f0(i, n) cin >> input[i];
    return input;
}

ll *inputArray(ll n)
{
    ll *input = new ll[n];
    f0(i, n) cin >> input[i];
    return input;
}

vector<vector<ll>> adj;
ll n, k, req;

ll func(ll u, ll par, ll max_height)
{

    bool leaf = true;
    ll h = LONG_LONG_MIN;
    for (ll to : adj[u])
    {
        h = max(func(to, u, max_height), h);
        leaf = false;
    }

    if (leaf)
        h = 0;
    h++;
    if (h == max_height)
    {
        if (par != 1 && u != 1)
            req++;
        return 0;
    }
    return h;
}

void solve()
{
    cin >> n >> k;
    adj.assign(n + 1, vector<ll>());
    for (ll i = 2; i <= n; i++)
    {
        ll t;
        cin >> t;
        adj[t].pb(i);
    }

    ll l = 1, r = n;
    while (l <= r)
    {
        ll m = (r - l) / 2 + l;
        req = 0;
        func(1, -1, m);

        if (req <= k)
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l << endl;
}

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}