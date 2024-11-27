
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
    int li = 0;
    int f = 0;

    ll count = 1;

    for(int i = 1; i < n; i++){
    	if(ele[i] > ele[i - 1] && f == 0){
    		count += (i - li + 1);
    	}
    	else if(ele[i] > ele[i - 1] && f == 1){
    		f = 0;
    		count += (i - li + 1);
    	}	
    	else if(ele[i] < ele[i - 1] && f == 0){
    		f = 1;
    		li = i - 1;
    		count += (i - li + 1);
    	}
    	else{
    		count += (i - li + 1);
    	}
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