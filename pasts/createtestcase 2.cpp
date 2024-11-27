
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

int count = 0;
 
void printstring(int j, string s){
	if(j == 12){
		cout << 12 << "\n";
		cout << (s + '0') << "\n";
		cout << 12 << "\n";
		cout << (s + '1') << "\n";
	}
	else{
		printstring(j + 1, (s + '0'));
		printstring(j + 1, (s + '1'));
	}

}

void solve() {
	cout << 4056 << "\n";
   	printstring(1, "");
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