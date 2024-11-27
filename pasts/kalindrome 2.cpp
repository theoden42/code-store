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
    vector<int> ele(n, 0);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	if(mp.find(ele[i]) == mp.end()){
    		mp[ele[i]] = 1;
    	}
    	else{
    		mp[ele[i]]++;
    	}
    }
    if(mp.size() <= 2){
    	cout << "YES" << "\n";
    }
    else{
    	int flag = 1;
    	for(int i = 0; i < n; i++){
    		if(ele[i] != ele[n - 1 - i]){
    			flag = 0;
    			break;
    		}
    	}
    	if(flag == 1){
    		cout << "YES" << "\n";
    		return;
    	}
    	int x1 = 1;
    	int x2 = 1;
    	for(int i = 0; i < n; i++){
    		if(ele[i] != ele[n - 1 - i]){
    			x1 = ele[i];
    			x2 = ele[n - 1 - i];
    			break;
    		}
    	}
		string s1 = "";
		string s2 = "";
		for(int i = 0; i < n; i++){
			if(ele[i] != x1){
				s1 += (char)('0' + ele[i]);
			}
		}
		for(int i = 0; i < n; i++){
			if(ele[i] != x2){
				s2 += (char)('0' + ele[i]);
			}
		}


		int flag1 = 0;
		for(int i = 0; i < s1.length(); i++){
			if(s1[i] != s1[s1.length() - 1 - i]){
				flag1 = 1;
				break;
			}
		}
		if(flag1 == 0){
			cout << "YES" << "\n";
			return;
		}

		int flag2 = 0;
		for(int i = 0; i < s2.length(); i++){
			if(s2[i] != s2[s2.length() - 1 - i]){
				flag2 = 1;
				break;
			}
		}
		if(flag2 == 0){
			cout << "YES" << "\n";
			return;
		}

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