
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m, 0);
    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }
    ll s1 = 0;
    s1 = accumulate(all(a), s1);
    ll s2 = 0;
    s2 = accumulate(all(b), s2);
    if(s1 != s2){
    	cout << 0 << "\n";
    	return;
    }
    vector<int> pref(n, 0);
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
    	pref[i] = a[i] + pref[i - 1];
    }
   	vector<int> kvals;
   	int ind = 0;
   	int j = 0;
    for(int i = 0; i < n && j < m; i++){
    	if(pref[i] - pref[ind] + a[ind] == b[j]){
    		ind = i + 1;
    		kvals.push_back(i - ind + 1);
    		j++;
    	}
    }
    if(j != m){
    	cout << "foo" << "\n";
    	return;
    }
    for(auto& x: kvals){
    	cout << x << " ";
    }
    cout << '\n';
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