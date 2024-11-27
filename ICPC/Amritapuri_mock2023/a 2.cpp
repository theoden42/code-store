
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
    string s;
    cin >> s;
    vector<int> d(n);
    for(int i = 0 ; i < n; i++){
    	cin >> d[i];
    }


    int mx = -1;
    int count = 0;

    for(int i = 0; i < n; i++){
    	if(s[i] == 'R' ){
    		mx = max(mx, d[i] + i);
    		continue;
    	}
    	else{
    		count++;
    		if(mx == -1 || mx < i){
    			cout << "-1\n";
    			return;
    		}
    		int temp = mx;
    		for(int j = i; j <= mx; j++){
    			temp = max(temp, d[j] + j);
    		}
    		i = mx;
    		mx = temp;
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