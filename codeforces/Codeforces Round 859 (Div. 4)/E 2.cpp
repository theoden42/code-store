
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

int query(int l, int r){
	cout << "? " << r - l + 1 << " ";
	for(int i = l; i <= r; i++){
		cout << i + 1 << " ";
	}
	cout << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> p(n, 0);
    p[0] = ele[0];
    for(int i = 1; i < n; i++){
    	p[i] = p[i - 1] + ele[i];
    }

    int l = 0;
    int u = n - 1;

    while(u - l >= 1){
    	int mid = (l + u) / 2;
    	int q1 = query(l, mid);
    	int s1 = p[mid] - p[l] + ele[l];

    	if(q1 > s1){
    		u = mid ;
    	} 
    	else{
    		l = mid + 1;
    	}
    }	

    cout << "! " << u + 1 << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}