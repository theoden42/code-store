
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
    vector<int> x(n, 0);
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> v[i];
    }
    // we have to search for the minimum value t, such that T(x) <= t
    auto check = [&](double t){
    	// we need to check if a value of x exists for the given value of t;
    	// T(x) = |x - x[i]| / v[i] <= t
    	double left = x[0] - t * v[0];
    	double right = x[0] + t * v[0];
    	for(int i = 1; i < n; i++){
    		double l = x[i] - t * v[i];
    		double r = x[i] + t * v[i];
    		left = max(l, left);
    		right = min(r, right);
    	}
    	if(right >= left){
    		return true;
    	}
    	return false;
    };

    double l = -1e9; double u = 1e10;	
  	double mn = 1e10;
    for(int i = 0; i < 100; i++){
    	double mid = l + (u - l) / 2;
    	if(check(mid)){
    		mn = mid; 
    		u = mid;
    	}
    	else{
    		l = mid;
    	}
    }
    cout << setprecision(6) << mn << "\n";
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