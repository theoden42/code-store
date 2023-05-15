
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
   	vector<int> b(n, 0);
   	for(int i = 0; i < n; i++){
   		cin >> b[i];
   	}
   	int index = -1;
   	for(int i = 0; i < n; i++){
   		if(b[i] == a[0]){
   			index = i;
   			break;
   		}
   	}
   	if(index == -1){
   		cout << "NO" << "\n";
   		return;
   	}
   	int x = index;

   	for(int j = 0; j < n; j++){
   		if(x == n){
   			x = 0;
   		}
   		if(b[x] != a[j]){
   			cout << "NO" << "\n";
   			return;
   		}
   		x++;
   	}
   	if(k == 0){
   		if(index == 0){
   			cout << "YES" << "\n";
   		}
   		else{
   			cout << "NO" << "\n";
   		}
   	}
   	else{
   		if(index == 0){
   			if(k == 1){
   				cout << "NO" << "\n";
   			}
   			else{
   				cout << "YES" << "\n";
   			}
   		}
   		else{
   			cout << "YES" << "\n";	
   		}
   	}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}