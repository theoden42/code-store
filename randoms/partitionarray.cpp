
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
    int n, k;
    cin >> n >> k;
    int mx = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    multiset<int> mst;
    for(int i = 0; i < n; i++){
        mst.insert(a[i]);
    }

    int count = 0;
    while(!mst.empty()){
        int a = *mst.begin();
        int b = a + k;
        auto it = mst.lower_bound(b);
        if(it == mst.end()){
            break;
        }
        else{
            count += 1;
            mst.erase(it);
            mst.erase(mst.begin());
        }
    }
    
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}