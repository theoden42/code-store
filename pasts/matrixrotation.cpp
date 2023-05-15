
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
	int ar[4];
	for(int i = 0; i < 4; i++){
		cin >> ar[i];
	}
	swap(ar[2], ar[3]);

	int min = 101; 
	int ind = -1;
	for(int i = 0; i < 4; i++){
		if(ar[i] < min){
			min = ar[i];
			ind = i;
		}
	}

	if(ar[(ind + 1) % 4] > ar[ind] && ar[(ind + 3) % 4] > ar[ind] && (ar[(ind + 2) % 4] > ar[(ind + 1) % 4] && ar[(ind + 2) % 4] > ar[(ind + 3) % 4])){
		cout << "Yes\n";
	}
	else{
		cout << "NO\n";
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