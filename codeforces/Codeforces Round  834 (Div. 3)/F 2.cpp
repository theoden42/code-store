
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
    int n, p;
    cin >> n >> p;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }


    vector<int> temp = ele;
    sort(all(ele));


    int mx = p - 1;

    for(int i = n - 1; i >= 0; i--){
    	if(ele[i] > mx){
    		continue;
    	}
    	if(ele[i] == mx){
    		mx -= 1;
    	}
    	else{
    		break;
    	}
    }

    int mn = 0;
    for(int i = 0; i < n; i++){
    	if(ele[i] < mx){
    		continue;
    	}
    	if(ele[i] == mx){
    		mx++;
    	}
    	else{
    		break;
    	}
    }

    if(mn > temp[n - 1]){
    	cout << mx - temp[n - 1] << "\n";
    	return;
    }
    else{
    	
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