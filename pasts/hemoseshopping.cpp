
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
    int n, x;
    cin >> n >> x;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    if(x <= n / 2){
    	cout << "YES\n";
    	return;
    }

    set<int> tmp;
    
  	for(int i = 0; i < x; i++){
  		tmp.insert(ele[i]);
  	}

  	for(int i = n - 1; i >= n - x; i++){
  		tmp.insert(ele[i]);
  	}
  	vector<int> final;
  	for(int i = 0; i < x; i++){
  		final[i] = *tmp.begin();
  		tmp.erase(tmp.begin());
  	}
  	for(int i = n - x; i < n; i++){
  		final[i] = *tmp.begin();
  		tmp.erase(tmp.begin());
  	}
  	for(int j = x; j < n - x; j++){
  		final[j] = ele[j];
  	}
  	int flag = 0;
  	for(int i = 0; i < n - 1; i++){
  		if(ele[i] > ele[i + 1]){
  			cout << "NO\n";
  			return;
  		}
  	}
  	cout << "YES\n";
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