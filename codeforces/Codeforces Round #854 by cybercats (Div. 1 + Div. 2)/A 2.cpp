
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


    vector<int> p(m);
    for(int i = 0; i < m; i++){
    	cin >> p[i];
    }


    map<int,int> mp;
    vector<int> rt(n, -1);

    int cnt = n - 1;
    int time = 0;

    for(int i = 0; i < m && cnt >= 0; i++){
    	time++;
    	if(mp.find(p[i]) != mp.end() && mp[p[i]] == 1){
    		continue;
    	}
    	else{
    		mp[p[i]] = 1;
    		rt[cnt--] = time;
    	}	
    }

    for(auto& x: rt){
    	cout << x << " ";
    }
    cout << "\n";



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