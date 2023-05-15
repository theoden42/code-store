
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
    string a, b;
    cin >> a >> b;
   	char c1 = a[a.size() - 1];
   	char c2 = b[b.size() - 1];
   	if(c1 == 'S' && c2 == 'L'){
   		cout << "<";
   	}
  	else if(c1 == 'L' && c2 == 'S'){
   		cout << ">";
   	}
   	else if(c1 == 'S' && c2 == 'M'){
   		cout << "<";
   	}
   	else if(c1 == 'M' && c2 == 'S'){
   		cout << ">";
   	}
   	else if(c1 == 'L' && c2 == 'M'){
   		cout << ">";
   	}
   	else if(c1 == 'M' && c2 == 'L'){
   		cout << "<";
   	}
   	else if(c1 == 'M' && c2 == 'M'){
   		cout << "=";
   	}
   	else if(c1 == 'S' && c2 == 'S'){
   		if(a.size() == b.size()){
   			cout << "=";
   		}
   		else if(a.size() > b.size()){
   			cout << "<";
   		}
   		else{
   			cout << ">";
   		}
   	}
   	else if(c1 == 'L' && c2 == 'L'){
   		if(a.size() > b.size()){
   			cout << ">";
   		}
   		else if(a.size() == b.size()){
   			cout << "=";
   		}
   		else{
   			 cout << "<";	
   		}
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