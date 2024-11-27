
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
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    int count = 0;


    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }


    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
    	if(mp.find(a[i]) == mp.end()){
    		vector<int> temp;
    		mp[a[i]] = temp;
    	}
    	mp[a[i]].push_back(i);
    }


    for(int j = 0; j < n; j++){
    	if(mp.find(b[j]) != mp.end()){
    		debug(b[j], mp[b[j]]);
    		if(mp[b[j]].size() != 0){
    			int x = mp[b[j]].back();
    			if(mp[b[j]].size() == 1){
    				mp[b[j]].clear();
    			}
    			else{
    				mp[b[j]].pop_back();
    			}	
    			a[x] = -1;
    			b[j] = -1;
    		}
    	}
    }

    debug(a, b);

   	auto countdigits = [&](int y){
   		int c = 0;
   		while(y != 0){
   			c++;
   			y /= 10;
   		}
   		return c;
    };

    mp.clear();

  	for(int i = 0; i < n; i++){
  		if(a[i] == -1){
  			continue;
  		}
  		int y = countdigits(a[i]);
  		if(y > 1){
  			a[i] = y;
  			count++;
  		}
  		if(mp.find(a[i]) == mp.end()){
  			vector<int> temp;
  			mp[a[i]] = temp;
  		}
  		mp[a[i]].push_back(i);
  	}
  	debug(a);
  	debug(count);


  	for(int i = 0; i < n; i++){
		if(b[i] == -1 || b[i] == 1){
			continue;
		}	
		int y = countdigits(b[i]);
		if(y == 1){
			if(mp.find(b[i]) != mp.end() && mp[b[i]].size() != 0){
				int tt = mp[b[i]].back();
				mp[b[i]].pop_back();
				b[i] = -1;
				a[tt] = -1;
			}
		}
		else{
			count++;
			if(mp.find(y) != mp.end() && mp[y].size() != 0){
				int tt = mp[y].back();
				mp[y].pop_back();
				b[i] = -1;
				a[tt] = -1;
			}
			else{
				b[i] = y;
			}
		}
  	}
  	debug(count);
  	debug(a, b);
  	for(int i = 0; i < n; i++){
  		if(a[i] != -1 && a[i] != 1){
  			count++;
  		}
  		if(b[i] != -1 && b[i] != 1){
  			count++;
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