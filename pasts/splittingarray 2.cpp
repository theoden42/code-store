
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
    int k, n;
    cin >> n >> k;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    // let M(ele) denote the maximum sum after splitting, 
    // to get the best split in the array we have to find the indexes ... , .... , .... such that max(sumofsegments) is min
    // Max(seg) <= t => 


   	auto check = [&](ll val){
   		ll sum = 0;
   		int c = 0;
   		for(int i = 0; i < n; i++){

   			sum = ele[i];
   			if(sum > val)return false;

   			int j = i + 1;
   			while(j < n && sum + ele[j] <= val){
   				sum += ele[j];
   				j++;
   			}

   			debug(val, i, j);
   			c++;
   			i = j - 1;
  		}
  		debug(val, c);
  		if(c <= k){
  			return true;
  		}
  		else{
  			return false;
  		}
   	};

   	ll l = 0;
   	ll u = 1e18;
   	ll mn = 1e18;

   	for(int i = 0; i < 70; i++){
   		ll mid = l + (u - l) / 2;
   		debug(mid);
   		if(check(mid)){
   			u = mid - 1;
   			mn = mid;
   		}
   		else{
   			l = mid + 1;
   		}
   	}
   	cout << mn << "\n";
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