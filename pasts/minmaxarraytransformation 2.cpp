
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
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    vector<pair<int,int>> d(n, {0, 0});
    for(int i = 0; i < n; i++){
    	// to find 
    	int val1 = *lower_bound(all(b), a[i]) - a[i];
    	d[i].first = val1;
    }

    vector<int> nextindex(n);
    nextindex[n - 1] = n - 1;


    for(int i = n - 2; i >= 0; i--){
    	if(b[i] >= a[i + 1]){
    		nextindex[i] = nextindex[i + 1];	
    	}
    	else{
    		nextindex[i] = i;
    	}
    }

    for(int i = 0; i < n; i++){
    	d[i].second = b[nextindex[i]] - a[i];
    }
    for(int i = 0; i < n; i++){
    	cout << d[i].first << " ";
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
    	cout << d[i].second << " ";
    }
    cout << '\n';
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