
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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int j = 0; j < n; j++){
    	cin >> b[j];
    }

    for(int i = 0; i < n - 1; i++){
    	if(a[i] <= a[n - 1] && b[i] <= b[n - 1]){
    		continue;
    	}
    	else if(a[i] > a[n - 1]){
    		int t = b[i];
    		b[i] = a[i];
    		a[i] = t;
    	}
    	else{
    		int t = a[i];
    		a[i] = b[i];
    		b[i] = t;
    	}
    }

    int flag = 1;

    for(int i = 0; i < n; i++){
    	if(a[i] > a[n - 1]){
    		flag = 0;
    		break;
    	}
    }
    for(int i = 0; i < n; i++){
    	if(b[i] > b[n - 1]){
    		flag = 0;
    		break;
    	}
    }
    if(flag){
    	cout << "Yes\n";
    }
    else{
    	cout << "No\n";
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