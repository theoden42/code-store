#include <bits/stdc++.h>
#include <debug.h>
using namespace std;
 
using ll = long long;
const ll MOD = 1e9 + 7;
 
ll fast_pow(ll a, ll b) { 
    ll res = 1; 
    for (a %= MOD; b; b >>= 1) { 
        if (b & 1) 
            res = res * a % MOD; 
        a = a * a % MOD; 
    } 
    return res; 
}
 
ll N;
 
int main() { 
    cin >> N;
    ll a = fast_pow(2, N * N);
    ll b = (N % 2 == 0 ? fast_pow(2, N * N / 4) : fast_pow(2, (N * N - 1) / 4) * 2 % MOD);
    debug(b);
    ll c = (N % 2 == 0 ? fast_pow(2, N * N / 2) : fast_pow(2, N * (N - 1) / 2) * fast_pow(2, N / 2 + 1) % MOD);
    ll d = b;
 
    cout << (a + b + c + d) % MOD * 250000002 % MOD << '\n';
}