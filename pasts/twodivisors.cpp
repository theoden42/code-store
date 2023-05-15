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
    vector<pair<int, int>> ans(n, {-1, -1});
    map<int,pair<int,int>> ref;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    for(int i = 0; i < n; i++){
    	int x = ele[i];
        if(ref.find(ele[i]) != ref.end()){
            ans[i] = ref[ele[i]];
            continue;
        }
        int count = 0;
        if(x % 2 == 0){
            while(x % 2 == 0){
                x /= 2;
                count++;
            }
            if(x == 1){
                ans[i].first = -1;
                ans[i].second = -1;
            }
            else{
                int y = pow(2, count);
                ans[i].first = y;
                ans[i].second = (ele[i] / y);

            }
            ref[ele[i]] = ans[i];
        }
        else{
            for(int j = 3; j * j <= ele[i]; j += 2){
                if(x % j == 0){
                    while(x % j == 0){
                        count++;
                        x /= j;
                    }
                    if(x == 1){
                        ans[i].first = -1;
                        ans[i].second = -1;
                        break;
                    }
                    else{
                        int y = pow(j, count);
                        ans[i].first = y;
                        ans[i].second = ele[i] / y;
                        break;
                    }

                }
            }
            ref[ele[i]] = ans[i];
        }
    }
    for(auto& x: ans){
    	cout << x.first << " ";
    }
    cout << '\n';
    for(auto&x : ans){
    	cout << x.second << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}