
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


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
void solve() {
    int n;
    cin >> n;
    vector<ll> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    ll gd = 0;	
    for(int i = 0; i < n; i++){
    	gd = gcd(ele[i], gd);
    }
    if(gd != 1){
    	cout << "-1\n";
    	return;
    }

    int mn = n;

    for(int i = 0; i < n; i++){
    	gd = ele[i];
    	int j = i + 1;
    	while(gd != 1 && j < n){
    		gd = gcd(gd, ele[j]);
    		j++;
    	}
    	if(gd != 1){
    		break;
    	}	
    	ll tgd = ele[j - 1];
    	int k = j - 2;
    	while(tgd != 1){
    		tgd = gcd(tgd, ele[k]);
    		k--;
    	}
    	mn = min(mn, j - k - 1);
    	i = k;
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