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
    vector<int> a(n, 0);
    vector<int> b(n - 1, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
    	cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n == 2 && b[0] > a[1]){
    	cout << min(b[0] - a[0], b[0] - a[1]) << "\n";
    	return;
    }

    int val = b[0] - a[0];
    if(val < 0){
    	cout << b[0] - a[1] << "\n";
    	return;
    }
    int count = 0;
    int flag = 0; 
    for(int i = 1, j = 1; i < n && j < n - 1; i++, j++){
    	if(b[j] - a[i] == val){
    		continue;
    	}
    	else if(count == 0){
    		count = 1; 
    		if(b[j] - a[i + 1] == val){
    			i++;
    		}
    		else{
    			flag = 1;
    			break;
    		}
    	}
    	else{
    		flag = 1;
    		break;
    	}
    }
    if(flag == 0){
    	int val2 = b[0] - a[1];
    	int flag2 = 0;
    	for(int i = 1, j = 0; i < n && j < n - 1; i++, j++){
    		if(b[j] - a[i] == val2){
    			continue;
    		}
    		else{
    			flag2 = 1; 
    			break;
    		}
    	}
    	if(flag2 == 0 && val2 > 0){
    		cout << min(val, val2) << "\n";
    	}
    	else{
    		cout << val << "\n";
    	}
    }
    else{
    	cout << b[0] - a[1] << "\n";
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