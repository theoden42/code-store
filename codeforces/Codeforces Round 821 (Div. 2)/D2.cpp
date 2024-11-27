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
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> index;
    for(int i = 0; i < n; i++){
    	if(a[i] != b[i]){
    		index.push_back(i);
    	}
    }
    if(index.size() % 2 != 0){
    	cout << "-1" << "\n";
    	return;
    }


    if(x >= y){
        ll ans = 0;
        if(index.size() == 0){
            cout << 0 << "\n";
            return;
        }

        if(index.size() != 2){
             ans = 1ll * y * (((int)index.size())/ 2);
        }
        else{
            if(index[0] == index[1] - 1){
                ans = min(x, 2 * y);
            }
            else{
                ans = y;
            }
        }
        cout << ans << "\n";
    }
    else{
        int ans = 0;
        vector<int> temp;
        for(int i = 0; i < index.size(); i++){
            int j = i + 1;
            while(j < index.size() && )
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