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
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int flag = 1;
    int count = 0;

    for(int i = 1; i <= n; i++){

        flag = 1;
        for(int i = 0; i < n - 1; i++){
            if(ele[i] > ele[i + 1]){
                flag = 0;
                break;
            }
        }

        if(flag == 1){
            break;
        }
    	
    	if(i % 2 == 0){
    		for(int j = 1; j <= n - 2; j += 2){
    			if(ele[j] > ele[j + 1]){
    				int temp = ele[j];
    				ele[j] = ele[j + 1];
    				ele[j + 1]  = temp;
    			}
    		}
    	}

    	else{
            for(int j = 0; j <= n - 3; j += 2){
                if(ele[j] > ele[j + 1]){
                    int temp = ele[j];
                    ele[j] = ele[j + 1];
                    ele[j + 1] = temp;
                }
            }
    	}
    	count++;
    }
    cout << count << "\n";
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