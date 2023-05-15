
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
    int x = a[0] - '0';
    int y = b[0] - '0';
    int xr = (x ^ y);
    for(int i = 1; i < n; i++){
    	 x = a[i] - '0';
    	y = b[i] - '0';
    	int t = (x ^ y);
    	if( t != xr){
    		cout << "NO\n";
    		return;
    	}
    }
    cout << "YES\n";


    int c = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] == '1')c++;
    }

    int ind = -1;	

    for(int i = 0; i < n - 1; i++){
    	if(a[i] == '1' && a[i + 1] == '1'){
    		ind = i;
    		break;
    	}
    }


   	if(xr & 1){// either 1, 0 or 0, 1
   		if(c & 1){
   			cout << c << "\n";
   			for(int i = 0; i < n; i++){
   				if(a[i] == '1'){
   					cout << i + 1 << " " << i + 1 << "\n";
   				}
   			}
   		}
   		else{
   			// there are even number of ones and even number and odd number of zeros then switching works, 
  			if(n & 1){
  				cout << n - c + 2 << "\n";
  				for(int i = 0; i < n; i++){
  					if(a[i] == '0'){
  						cout << i + 1 << " " << i + 1 << "\n";
  					}
  				}
  				cout << "2 " << n  << "\n";
  				cout << "1 1\n";
  			}
  			else{
  				cout << n - c + 1 << "\n";
  				cout << 1 << " " << n << "\n";
  				for(int i = 0; i < n; i++){
  					if(a[i] == '0'){
  						cout << i + 1 << " " << i + 1 << "\n";
  					}
  				}
  			}
   		}
   	}


   	else{
   		if(c & 1){
   			if(n & 1){
   				cout << n - c + 2 << "\n";
   				for(int i = 0; i < n; i++){
   					if(a[i] == '0'){
   						cout << i + 1 << " " << i + 1 << "\n";
   					}
   				}
   				cout << "2 " << n << "\n";
   				cout << "1 1\n";
   			}
   			else{
   				cout << n - c + 1 << "\n";
   				cout << 1 << " " << n << "\n";
   				for(int i = 0; i < n; i++){
   					if(a[i] == '0'){
   						cout << i + 1 << " " << i + 1 << "\n";
   					}
   				}
   			}
   		}
   		else{
   			cout << c << "\n";
   			for(int i = 0; i < n; i++){
   				if(a[i] == '1'){
   					cout << i + 1 << " " << i + 1 << "\n";
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