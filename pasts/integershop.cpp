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
    int n;
    cin >> n;
    vector<pair<ll, ll>> range;
    vector<ll> cost;
    for(int i = 0; i < n; i++){
    	ll l, r, c;
    	cin >> l >> r >> c;
    	range.emplace_back(l, r);
    	cost.push_back(c);
    }
    auto itA = range.begin();
    auto itB = cost.begin();

    ll sum = *itB;
    ll costmax = *itB;
    ll costmin = *itB;
    ll max = (*itA).second;
    ll min = (*itA).first;

    cout << sum << "\n";
    itA++;
    itB++;

	while(itA != range.end() && itB != cost.end()){
		int l1 = itA -> first;
		int r1 = itA -> second;
		int cr = *itB;
		int flag = 0;
		int force = 0;
		if(l1 == min && r1 == max && cr <= sum){
			sum = cr;
			flag = 1;
		}
		else if((l1 == min && r1 > max)|| (l1 < min && r1 == max)){
			sum = cr;
			flag = 1;
		}
		if(l1 == min && cr < costmin){
			costmin = cr;
		}
		if(r1 == max && cr < costmax){
			costmax = cr;
		}
		if(l1 < min && r1 > max){
			sum = cr;
			max = r1;
			min = l1;
			costmax = cr;
			costmin = cr;
			force = 1;
			flag = 1;
		}
		else if(r1 > max){
			max = r1;
			costmax = cr;
			force = 1;
		}
		else if(l1 < min){
			min = l1;
			costmin = cr;
			force = 1;
		}

		if(!flag){
			if(force || (sum > costmax + costmin)){
				sum = costmax + costmin;
			}			
		}
		cout << sum << "\n";
		itA++;
		itB++;

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