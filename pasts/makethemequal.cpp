
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;
    char ch;
    cin >> ch;
    string s;
    cin >> s;	
    int count = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] != ch){
    		count++;
    	}
    }
    if(count == 0){
    	cout << 0 << "\n";	
    	return;
    }
	if(s[n - 1] == ch){
		cout << 1 << "\n";
		cout << n << "\n";
		return;
	}
	else{
		set<int> st;
		for(int i = 0; i < n; i++){
		 	if(s[i] != ch){
		 		for(int j = 1; j * j <= i + 1; j++){
		 			if((i + 1) % j == 0){
		 				st.insert(j);
		 				st.insert((i + 1)/j);
		 			}
		 		}
		 	}
		}
		if(st.size() == n){
			cout << 2 << "\n";
			cout << n - 1 << " " << n << "\n";
		}
		else{
			cout << 1 << " \n";
			for(int i = 1; i <= n; i++){
			if(st.find(i) == st.end()){
				cout << i << "\n";
				return;
			}
		}
		}
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