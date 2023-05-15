#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    ll n;
    cin >> n;
    vector<ll> ele(n, 0);
    unordered_map<ll, ll> freq;
    ll sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	sum += ele[i];
    	if(freq.find(ele[i]) == freq.end()){
    		freq[ele[i]] = 1;
    	}
    	else{
    		freq[ele[i]]++;
    	}
    }
    vector<ll> gen;
    sort(ele.begin(), ele.end());
    vector<ll> curr;
    if(freq.find(sum) != freq.end()){
    	gen.push_back(sum);
    }
    else{
    	curr.push_back(sum);
    }
    int i = 0;
    while(i < n - 1 && gen.size() <= n && curr.size() <= n){
    	ll x = curr.back();
    	curr.pop_back();
    	ll f = x / 2;
    	ll c = ceil(x / 2.0);
    	if(freq.find(f) != freq.end() && freq[f] != 0){
    		freq[f]--;
    		gen.push_back(f);
    	}
    	else{
    		curr.push_back(f);
    	}
    	if(freq.find(c) != freq.end() && freq[c] != 0){
    		freq[c]--;
    		gen.push_back(c);
    	}
    	else{
    		curr.push_back(c);
    	}
    	i++;
    }
    sort(gen.begin(), gen.end());
    if(gen == ele){
    	cout << "YES" << "\n";
    }
    else{
    	cout << "NO" << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}