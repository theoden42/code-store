
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(int a, int b){
    return (a * b) / gcd(a, b);
}


void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;


    vector<int> f1;
    vector<int> f2;
    vector<int> f3;


    for(int i = 1; i * i <= a; i++){
        if(a % i == 0){
            f1.push_back(i);
            if(i != a / i)
                f1.push_back(a / i);
        }
    }


    for(int i = 1; i * i <= b; i++){
        if(b % i == 0){
            f2.push_back(i);
            if(i != b / i)
                f2.push_back(b / i);
        }
    }

    for(auto& x: f1){
        for(auto& y: f2){
            f3.push_back(x * y);
        }
    }

    sort(all(f3));

    for(int i = 0; i < f3.size(); i++){
        int x = f3[i];
        int y = (a * b) / x;
        int mul1 = a / x + 1;
        int mul2 = b / y + 1;
        if(x * mul1 <= c && y * mul2 <= d){
            cout << x * mul1 << " " << y * mul2 << "\n";
            return;
        }
    }

    cout << "-1 -1\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}