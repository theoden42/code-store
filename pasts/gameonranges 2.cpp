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

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first){
		return true;
	}
	else if(b.first < a.first){
		return false;
	}
	else{
		if(a.second > b.second){
			return true;
		}
		else{
			return false;
		}
	}
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ele(n, pair<int, int>());
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	ele[i] = {x,y};
    }
    sort(ele.begin(), ele.end(), cmp);
    for(int i = 0; i < n; i++){
    	if(ele[i].first == ele[i].second){
    		cout << ele[i].first << " " << ele[i].second << " " << ele[i].first << "\n";
    	}
    	else{
    		assert(i + 1 < n);
    		if(ele[i].second == ele[i + 1].second){
    			cout << ele[i].first << " " << ele[i].second << " " << ele[i + 1].first - 1 << "\n";
    		}
    		else{
    			cout << ele[i].first << " " << ele[i].second << " " << ele[i + 1].second + 1 << "\n";
    		}
    	}
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