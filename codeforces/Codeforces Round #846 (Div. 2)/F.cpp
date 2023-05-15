
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
    int n, d;
    cin >> n >> d;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int sum = 0;
    int i = 0;
    int j = n - 1;
    int count = 0;
    sort(all(ele));
    while(i < j){
    	sum = ele[j];
    	while(sum =< d && i < j){
    		sum += ele[j];
    		i++;
    	}

    	if(sum > d){
    		count++;
    		sum = 0;
    	}
    	else{
    		break;
    	}
    	j--;
    }
    cout << count << "\n";
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