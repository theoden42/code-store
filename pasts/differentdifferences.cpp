
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
    int k, n;
    cin >> k >> n;
    int element = 1;
    int character = 0;
    vector<int> ans(k);
    // for(int i = 1; i <= k; i++){
    // 	if(element + character <= n){
    // 		cout << element + character << " ";
    // 		element = element + character;
    // 		character += 1;
    // 	}
    // 	else{
    // 		cout << element + 1<< " ";
    // 		element += 
    // 	}
    // }

    //how manydifferent values can exist 
    int count = 0;
    for(int i = 1; i <= k; i++){
    	int val = ((i - 1) * i) / 2 - i + 1;
    	if(val > n - k){
    		break;
    	}
    	else{
    		count++;
    		cout << element + character << " ";
    		element = element + character;
    		character++;
    	}
    }
    for(int i = count + 1; i <= k; i++){
    	cout << ++element << " ";
    }


    cout << "\n";
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