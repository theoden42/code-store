
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
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int p = 0, neg = 0;

    for(int i = 0; i < n; i++){
    	if(ele[i] > 0){
    		p++;
    	}
    	else{
    		neg++;
    	}
    }
    vector<int> maximum;
    vector<int> minimum;

    for(int i = 0; i < n; i++){
    	int mx = min(p, i + 1);
    	mx -= (i + 1 - mx);
    	int mn = p;
    	if((i + 1) & 1){
    		if(neg >= (i + 1) / 2){
    			mn = 1;
    		}
    		else{
    			mn = (i + 1) - 2 * neg;
    		}
    	}
    	else{
    		if(neg >= (i + 1) / 2){
    			mn = 0;
    		}
    		else{
    			mn = (i + 1) - 2 * neg;
    		}
    	}
    	maximum.push_back(mx);
    	minimum.push_back(mn);
    }
    for(int i = 0; i < n; i++){
    	cout << maximum[i] << " ";
    }
    cout << "\n" ;	
    for(int i = 0; i < n; i++){
    	cout << minimum[i] << " ";
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