
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ele(k, 0);
    for(int i = 0; i < k; i++){
    	cin >> ele[i];
    }
    sort(ele.rbegin(), ele.rend());
    int x = m;
 	int i = 0;
 	int flag = 0;
 	int f1 = 1;
 	while(i < k && x > 0){
 		int cols = ele[i] / n;
 		if(cols < 2){
 			f1 = 0;
 			break;
 		}
 		else if(cols > 2){
 			if(x >= 2){
 				x -= min(x, cols);
 				flag++;
 			}
 			else{
 				if(flag >= 1){
 					x = 0;
 					flag--;
 				}
 				else{
 					f1 = 0;
 					break;
 				}
 			}
 		}
 		else{
 			if(x >= 2){
 				x -= 2;
 			}
 			else{
 				if(flag >= 1){
 					x = 0;
 					flag--;
 				}
 				else{
 					f1 = 0;
 					break;
 				}
 			}

 		}
 		i++;
 	}
 	if(x > 0){
 		f1 = 0;
 	}
 	// cout << f1 << "\n";
 	int f2 = 1;
 	flag = 0;
 	x = n;
 	i = 0;
 	while(i < k && x > 0){
 		int cols = ele[i] / m;
 		if(cols < 2){
 			f2 = 0;
 			break;
 		}
 		else if(cols > 2){
 			if(x >= 2){
 				x -= min(x, cols);
 				flag++;
 			}
 			else{
 				if(flag >= 1){
 					x = 0;
 					flag--;
 				}
 				else{
 					f2 = 0;
 					break;
 				}
 			}
 		}
 		else{
 			if(x >= 2){
 				x -= 2;
 			}
 			else{
 				if(flag >= 1){
 					x = 0;
 					flag--;
 				}
 				else{
 					f2 = 0;
 					break;
 				}
 			}

 		}
 		i++;
 	}
 	if(x > 0){
 		f2 = 0;
 	}
 	if(f1 || f2){
 		cout << "Yes" << "\n";
 	}
 	else{
 		cout << "No" << "\n";
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