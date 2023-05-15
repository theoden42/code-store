
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

double binpow(double a, int b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return (ans);
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> factorial(11, 1);
    for(int i = 1; i <= 10; i++){
    	factorial[i] = i * factorial[i - 1];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '+'){
    		count++;
    	}
    	else if(s[i] == '-'){
    		count--;
    	}
    }
    int count2 = 0;
    int question = 0;
    for(int i = 0; i < n; i++){
    	if(t[i] == '+')
    		count2++;
    	else if(t[i] == '-'){
    		count2--;
    	}
    	else{
    		question++;
    	}
    }
    debug(count, count2, question);
    if(count2 == count){
    	if(question % 2 != 0){
    		cout << 0 << "\n";
    		return;
    	}
    	else{
    		double nck = factorial[question]/(factorial[question/2] * factorial[question/2]);
    		double ans = nck * pow(0.5, question);
    		cout << setprecision(10) << ans << "\n";
    	}
    }
    else{
    	int dist = abs(count - count2);
    	if(dist > question){
    		cout << 0 << "\n";
    	}
    	else{
    		double nck = factorial[question]/(factorial[(question + dist) / 2] * factorial[(question - dist)/2]);
    		double ans = nck * pow(0.5, question);
    		cout << setprecision(10) << ans << "\n";
    	}
    }
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