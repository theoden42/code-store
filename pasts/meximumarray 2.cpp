/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
        cin >> ele[i];
    }
    int lindex = 0;

    vector<int> bval;

    map<int,queue<int>> mp;

    for(int i = 0; i < n; i++){
        mp[ele[i]].push(i);
    }

    while(lindex != n){
        int mx = lindex;

        for(int i = 0; i <= n; i++){
            if(mp.find(i) == mp.end() || mp[i].size() == 0){
                bval.push_back(i);  
                lindex = mx + 1;
                break;
            }
            else{
                int t = -1;
                while(t < lindex && !(mp[i].empty())){
                    t = mp[i].front();
                    debug(t, lindex);
                    mp[i].pop();
                }
                debug(t, lindex);
                if(mp[i].empty() && t < lindex){
                    bval.push_back(i);
                    lindex = mx + 1;
                    break;
                }
                mx = max(mx, t);
            }
        }
    }
    cout << bval.size() << "\n";
    for(auto& x: bval){
        cout << x << " ";
    }
    cout << "\n";  

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