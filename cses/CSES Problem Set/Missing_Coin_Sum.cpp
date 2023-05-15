
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    sort(all(ele));

    int sum = 0;
    int lastsum = 0;
    int count = 0;


    for(int i = 0; i < n; i++){
    	sum += ele[i];
    	if(sum == lastsum + 1){
    		lastsum = sum;
    	}
    	else{
            int diff = sum - lastsum - 1;
            if(diff <= lastsum){
                lastsum = sum;
                continue;
            }
            else{
                cout << lastsum + 1 << "\n";
                return;
            }
    	}
    }
    cout << sum + 1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}