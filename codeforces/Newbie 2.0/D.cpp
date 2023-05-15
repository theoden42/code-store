
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
    int k;
    cin >> k;

    int h = __builtin_popcount(n);
    if(k < h || k > n){
    	cout << "NO\n";
    }
    else{
    	cout << "YES\n";

        multiset<int> st;
        int count = 0;
        while(n != 0){
            if(n & 1){
                st.insert(1 << count);
            }
            n /= 2;
            count++;
        }

        while(st.size() < k){
            auto it = (--st.end());
            int v = *it;
            st.erase(it);
            st.insert(v / 2);
            st.insert(v / 2);
        }
        while(!st.empty()){
            cout << *st.begin() << " ";
            st.erase(st.begin());
        }
        cout << "\n";

    }

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