
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
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> temp = ele;
    sort(all(temp));
    int count = 0;
    int lastpushed = -1;
    for(int i = 0; i < n; i++){	
    	if(i == 0){
    		count++;
    		lastpushed = ele[i];
    		continue;
    	}
    	else{
    		if(ele[i] != *upper_bound(all(temp), lastpushed)){
    			count++;
    		}
    		lastpushed = ele[i];
    	}
    }
    if(count <= k)cout << "Yes\n";
    else cout << "No\n";
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