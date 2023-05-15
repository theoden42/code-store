
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
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    int ind = 0;

    for(int i = 0; i < n; i++){
    	if(b[i] > a[0]){
    		ind = i;
    		break;
    	}
    }

    if(ind == 0){
    	cout << "0\n";
    	return;
    }

    int mn = ind;
    vector<int> bmax(n);
    bmax[0] = b[0];

    for(int i = 1; i < n; i++){
    	if(b[i] > bmax[i - 1]){
    		bmax[i] = b[i];
    	}
    	else{
    		bmax[i] = bmax[i - 1];
    	}
    }

    int j = ind;
    int amin = a[0];

   	for(int i = 0; i < ind; i++){
   		if(a[i] < amin){
   			amin = a[i];
   		}
   		else{
   			continue;
   		}
   		int c = i;
   		while(j > 0 && bmax[j - 1] > a[i]){
   			j--;
   		}
   		mn = min(mn, j + i);
   	}
   	cout << mn << "\n";

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