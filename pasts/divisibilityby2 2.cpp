
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
    vector<int> ele(n, 0);
    int t = 0;

    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	int x = ele[i];
    	while(x % 2 == 0){
    		t++;
    		x /= 2;
    	}
    }
    debug(t);
    if(t >= n){
    	cout << 0 << "\n";
    	return;
    }
    vector<int> pows;

    for(int i = 1; i <= n; i++){
    	int c = 0;
    	int x = i;
    	while(x % 2 == 0){
    		c++;
    		x /= 2;
    	}
    	pows.push_back(c);
    }

    sort(all(pows));
    debug(pows);


    int sum = t;
    for(int i = n - 1; i >= 0; i--){
    	sum += pows[i];
    	debug(sum);
    	if(sum >= n){
    		cout << n - i << "\n";
    		return;
    	}
    }


    cout << "-1\n";
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