
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
    vector<int> p(n);
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    }
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	mp[p[i]] = i;
    }


    int count = 0;
    vector<int> temp = p;

    int f = 0;
    int ind = -1;
  	for(int i = 0; i < n - 1; i++){
  		if(p[i] == i + 2 && p[i + 1] == i + 1){
  			f = 1;
  			ind = i; 
  			break;
  		}
  	}
  	if(f){
  		int count = 0;
  		for(int i = 0; i < n; i++){
  			if(i == ind || i == ind + 1){
  				continue;
  			}
  			if(temp[i] == i + 1){
  				continue;
  			}
  			else{
  				debug(i, i + 1, mp[i + 1]);
  				int ind = mp[i + 1];
  				temp[ind] = temp[i];
  				temp[i] = i + 1;
  				count++;
  				mp[i + 1] = i;
  				mp[temp[ind]] = ind;
  			}
  		}
  		cout << count << "\n";
  	}
  	else{
  		if(temp[0] != 2){
  			int ind = mp[2];
  			temp[ind] = temp[0];
  			temp[0] = 2;
  			count++;
  			mp[2] = 0;
  			mp[temp[ind]] = ind;
  		}
  		if(temp[1] != 1){
  			int ind = mp[1];
  			temp[ind] = temp[1];
  			temp[1] = 1;
  			count++;
  			mp[1] = 2;
  			mp[temp[ind]] = ind;
  		}
  		for(int i = 2; i < n; i++){
  			if(temp[i] == i + 1)continue;
  			else{
  				int ind = mp[i + 1];
  				temp[ind] = temp[i];
  				temp[i] = i + 1;
  				count++;
  				mp[i + 1] = i;
  				mp[temp[ind]] = ind;
  			}
  		}
  		cout << count << "\n";

  	}
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