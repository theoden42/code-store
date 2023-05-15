
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

int query(int i, int j, int type){
	if(type == 0){
		cout << "AND " << i << " " << j << endl;
	}
	else if(type == 1){
		cout << "OR " << i << " " << j << endl;
	}
	else{
		cout << "XOR " << i << " " << j << endl;
	}
	int ans;
	cin >> ans;
	if(ans == -1)exit(0);
	return ans;

}

void soln(vector<int>& ans){
	cout << "! ";
	for(auto& x: ans){
		cout << x << " ";
	}
	cout << endl;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

void solve() {
	int n;
	cin >> n;

    int val1 = query(1, 2, 0);
    int val3 = query(1, 2, 2);

    int ans1 = 0;
    int ans2 = 0;

    int i = 0;
    while(val1 != 0 || val3 != 0){
    	int x = (val1 & 1);
    	int y = (val3 & 1);
    	if(x == 1){
    		ans1 += binpow(2, i);
    		ans2 += binpow(2, i);
    	}
    	else if(y == 1){
    		ans1 += binpow(2, i);
    	}
    	val1 >>= 1;
    	val3 >>= 1;
    }

    int val4 = query(2, 3, 1);

    if((val4 | ans2) != val3){
    	swap(ans1, ans2);
    }
    vector<int> nums;
    nums.push_back(ans1);
    nums.push_back(ans2);

    int xr = ans2;

   	for(int i = 3; i <= n; i++){
   		int temp = query(i - 1, i, 2);
   		xr = (temp ^ xr);
   		nums.push_back(xr);
   	}
   	soln(nums);
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