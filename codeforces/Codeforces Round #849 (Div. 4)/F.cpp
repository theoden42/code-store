
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

int sumdigits(int a){
    ll sum = 0;
    while(a != 0){
        sum += (a % 10);
        a /= 10;
    }
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
        cin >> ele[i];
    }

    multiset<int> mst;
    for(int i = 0; i < n; i++){
        mst.insert(i);
    }

    for(int i = 1; i <= q; i++){
        int t;
        cin >> t;
        if(t == 1){
            debug(mst);
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if(mst.empty())continue;

            auto start = mst.lower_bound(l);
            while(start != mst.end() && *start <= r){
                int ind = *start;
                int val = sumdigits(ele[ind]);
                ele[ind] = val;
                if(val < 10){
                    mst.erase(start);
                }
                start = mst.upper_bound(ind);
            }
        }   
        else{
            int x;
            cin >> x;
            x--;
            cout << ele[x] << "\n";
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