
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
	string s;
	cin >> s;


	string temp = "";

	for(int i = 1; i <= 1000; i++){
		if( i % 3 == 0 && i % 5 == 0){
			temp += "FB";
		}
		else if(i % 3 == 0){
			temp += "F";
		}
		else if(i % 5 == 0){
			temp += "B";
		}
	}

	int flag = 0;
	for(int i = 0; i <= temp.size() - n; i++){
		string cmp = temp.substr(i, n);
		if(cmp == s){
			flag = 1;break;
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