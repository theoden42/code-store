
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
	int n, k;
	cin >> n >> k;
    string a, b;
    cin >> a >> b;
    map<char,int> mp1;
    map<char,int> mp2;

    sort(all(a));
    sort(all(b));

    for(int i = 0; i < n; i++){
    	mp2[b[i]]++;
    	mp1[a[i]]++;
    }

    debug(mp1, mp2);


  	for(int i = 'z'; i >= 'a'; i--){
  		int x = mp1[(char)i];
  		int y = mp2[(char)i];
  		debug(x, y, (char)i);
  		if(x > y){
  			cout << "No\n";
  			return;
  		}
  		else if(x == y){
  			continue;
  		}
  		else{
  			int dif = (y - x);
  			if(dif % k != 0){
  				cout << "No\n";
  				return;
  			}
  			dif = dif / k;
  			debug(dif);
  			debug(mp1, mp2);
  			for(int j = i - 1; j >= 'a'; j--){
  				if(mp1.find(j) != mp1.end() && mp1[j] >= k){
  					debug(dif, mp1[j] / k, j);
  					int val = min(dif, mp1[j] / k);
  					mp1[j] -= k * val;
  					dif -= val;

  				}
  			}
  			debug(mp1, mp2, dif);
  			if(dif != 0){
  				cout << "No\n";
  				return;
  			}
  		}
  	}


  	cout << "Yes\n";

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