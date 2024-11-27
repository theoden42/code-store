
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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n), b(m);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	a[i] = {x, -1 * (i + 1)};
    }

    for(int i = 0; i < m; i++){
    	int x;
    	cin >> x;
    	b[i] = {x, i + 1};
    }

    vector<pair<int,int>> c;
    vector<int> ansa(n);
    vector<int> ansb(m);


    for(int i = 0; i < n; i++){
    	c.push_back(a[i]);
    }
    for(int i = 0; i < m; i++){
    	c.push_back(b[i]);
    }

    sort(all(c));

    debug(c);

    for(int i = 0; i < c.size(); i++){
    	int ind = c[i].second;
    	if(ind < 0){
    		ansa[-1 * ind - 1] = i + 1;
    	}
    	else{
    		ansb[ind - 1] = i + 1;
    	}
    }

    for(auto x: ansa){
    	cout << x << " ";
    }
    cout << "\n";
    for(auto x: ansb){
    	cout << x << " ";
    }
    cout << endl;

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