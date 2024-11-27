
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
    vector<int> ele(n);
    vector<int> temp(n + 1, 0);

    for(int i = 0; i < n; ++i){
    	cin >> ele[i];
    }

    vector<int> prefix(n, 0);
    prefix[0] = ele[0];


    for(int i = 1; i < n; i++){
    	prefix[i] = prefix[i - 1] + ele[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < i; j++){
    		int sum = prefix[i] - prefix[j] + ele[j];
    		if(sum <= n){
    			temp[sum]++;
    		}
    	}
    }


    for(int i = 0; i < n; i++){
    	if(temp[ele[i]] != 0)count++;
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