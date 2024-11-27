// Code written by zaixo
// I do not believe in superiority but " S U P R E M A C Y "
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
typedef vector<pll> vp;
template <typename T>
inline void inp(T& a, int n) { for(int i=0; i<n; ++i) cin >> a[i]; }
template <typename T>
inline void outs(const T& a) { for(const auto& e : a) cout << e << " "; cout << endl; }
#define pb push_back
#define eb emplace_back
#define MP(a, b) make_pair(a, b)
#define endl '\n'
#define yaya cout << "YES" << endl
#define nono cout << "NO" << endl
void speedy(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
void flaggy(bool flag){cout<<(flag?"YES":"NO")<<endl;}
bool sorta(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.second < b.second);}
bool sortd(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.second > b.second);}
const int N = 300000 + 5;
const int MOD = 998244353;
const int MOD1 = 1e9+7;
 
// Mathematical functions
ll gcd(ll a, ll b){return __gcd(a, b);} //__gcd 
ll lcm(ll a, ll b){return (a*b)/gcd(a, b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
 
//Bits
string decToBinary(int n){ bitset<32> binary(n); return binary.to_string();}
int binaryToDecimal(const string& binary_str){ return bitset<32>(binary_str).to_ulong();}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
 
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> divs;
    vector<int> idx(x + 1, -1);
    for (int i = 1; i <= x; i++) {
      if (x % i == 0) {
        idx[i] = int(divs.size());
        divs.push_back(i);
      }
    }
    int sz = int(divs.size());
    int ans = 1;
    vector<bool> can(sz, false);
    can[0] = true;
    for (int num : a) {
      if (x % num != 0) {
        continue;
      }
      if (can[idx[x / num]]) {
        ans += 1;
        can.assign(sz, false);
        can[0] = true;
        can[idx[num]] = true;
        continue;
      }
      for (int j = sz - 1; j >= 0; j--) {
        if (divs[j] % num == 0 && can[idx[divs[j] / num]]) {
          can[j] = true;
        }
      }
    }
    cout << ans << '\n';
}
 
int main() {
  speedy();
  ll t=1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}