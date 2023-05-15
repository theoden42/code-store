
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
    vector<int> ind(n + 1);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	ind[ele[i]] = i;
    }

    int flag = 1;
    for(int i = 0; i < n; i++){
    	if(ele[i] != i + 1){
    		flag = 0;
    		break;
    	}
    }

    if(flag){
    	cout << "0\n";
    	return;
    }

    int pos = ind[1];
    int len = 0;
    int start = 1;
    int mn = n;

    for(int i = 1; i <= n; i++){
    	if(ind[i] >= pos){
    		len++;
    		pos = ind[i];
    	}
    	else{
    		int step = max({start - 1, n - i + 1});
    		debug(step, i, start);
    		mn = min(step, mn);
    		start = i;
    		pos = ind[i];
    		i--;
    	}
	}
	int step = max({start - 1, 0});
	mn = min(step, mn);
	cout << mn << "\n";
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