
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
	cin >> n; // input the size of the array
	int arr[n]; // create an array of size n
	for(int i = 0; i < n; i++){
		cin >> arr[i]; // input all the number of the array
	}
	long long c = 0;
	for(int i = 0; i < n; i++){
		c = c + arr[i];
	}
	cout << c << "\n"; 
	//Can you tell what will be the output in case of input : 
	/* 5
	   1 2 3 4 5
	*/
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