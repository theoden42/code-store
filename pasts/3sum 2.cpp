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
    map<int,int> mp;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];

    }
    vector<int> rem(n, 0);
    for(int i = 0; i < n; i++){
    	rem[i] = ele[i] % 10;
        mp[rem[i]]++;
    }
    // for(int i = 0; i < n; i++){
    //     cout << rem[i] << " ";
    // }
    // cout << "\n";
   	for(int i = 0; i <= 3; i++){
   		if(mp.find(i) != mp.end()){
   			map<int,int> mp2;
            int index = -1;
            for(int j = 0; j < n; j++){
                if(rem[j] == i){
                    index = j;
                    break;
                }
            }
            for(int j = 0; j < n; j++){
                if(j == index){
                    continue;
                }
                int x = (3 - i) - rem[j];
                if(mp2.find(x) != mp2.end()){
                    cout << "YES" << "\n";
                    return;
                }
                mp2[rem[j]]++;
            }
   		}
   	}	
    for(int i = 0; i <= 13; i++){
        if(mp.find(i) != mp.end()){
            map<int,int> mp2;
            int index = -1;
            for(int j = 0; j < n; j++){
                if(rem[j] == i){
                    index = j;
                    break;
                }
            }
            for(int j = 0; j < n; j++){
                if(j == index){
                    continue;
                }
                int x = (13 - i) - rem[j];
                if(mp2.find(x) != mp2.end()){
                    cout << "YES" << "\n";
                    return;
                }
                mp2[rem[j]]++;
            }
        }
    }   
    for(int i = 0; i <= 23; i++){
        if(mp.find(i) != mp.end()){
            map<int,int> mp2;
            int index = -1;
            for(int j = 0; j < n; j++){
                if(rem[j] == i){
                    index = j;
                    break;
                }
            }

            for(int j = 0; j < n; j++){
                if(j == index){
                    continue;
                }
                int x = (23 - i) - rem[j];
                if(mp2.find(x) != mp2.end()){
                    cout << "YES" << "\n";
                    return;
                }
                mp2[rem[j]]++;
            }
        }
    }   
    cout << "NO" << "\n";
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