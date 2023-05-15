
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
    string a, b;
    cin >> a >> b;
    if(a == b){
    	cout << 0 << "\n";
    	return;
    }


    int count = 0;
    for(auto& c : a){
    	if(c == '1')count++;
    }
    if(count == 0){
    	cout << "-1\n";
    	return;
    }

   	if(n == 2){
   		cout << "1\n";
   		return;
   	}

   	int count2 = 0;
   	for(int i = 0; i < n; i++){
   		if(b[i] == '1')count2++;
   	}

   	if(count2 != count){
   		cout << "-1\n";
   		return;
   	}

   	int c1 = 0, c2 = 0;
   	for(int i = 0; i < n; i++){
   		if(a[i] == '1' && b[i] == '0')c1++;
   		if(a[i] == '0' && b[i] == '1')c2++;
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