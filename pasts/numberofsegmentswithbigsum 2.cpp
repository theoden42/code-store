
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
    ll s;
    cin >> n >> s;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    ll sum = 0;
    int i = 0, j = 0;
    ll count = 0;
    sum = ele[0];

    while(i < n){
        while(sum < s && j < n){
            j++;
            sum += ele[j];
        }
        if(sum >= s)
            count += n - j;
        debug(i, j, count, sum, s);

        sum -= ele[i];
        i++;
    }

    cout << count << "\n";
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