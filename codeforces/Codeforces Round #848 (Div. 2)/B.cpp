
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


int minmoves(int pos1, int pos2, int n, int d){
	int moves1 = pos2 - pos1;
	int moves2 = 1e9;
	if(d < n - 1)
		moves2 = d + 1 - (pos2 - pos1);
	return min(moves1, moves2);
}	

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> p(n);
    vector<int> a(m);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    	mp[p[i]] = i;
    }
    for(int i = 0; i < m; i++){
    	cin >> a[i];
    }

    int good = 0;
    for(int i = 0; i < m - 1; i++){
    	if(mp[a[i]] < mp[a[i + 1]] && mp[a[i + 1]] <= mp[a[i]] + d){
    		continue;
    	}
    	else{
    		debug(i);
    		good = 1;
    		break;
    	}
    }


    if(good){
    	cout << "0" << "\n";
    	return;
    }

    int mn = n;
    for(int i = 0; i < m - 1; i++){
    	mn = min(mn, minmoves(mp[a[i]], mp[a[i + 1]], n, d));
    }
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