
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k, 0);
    for(int i = 0; i < k; i++){
    	cin >> b[i];
    }
    int i = 0, j = 0;
    while(i < n && j < k){
    	cout << a[i] << " " << b[j] << "\n";
    	if(a[i] == b[j]){
    		i++;
    		j++;
    		continue;
    	}
    	if(a[i] < b[j] && b[j] % m == 0){
    		int count = 0;
    		for(int k = i; k < n; k++){
    			if(a[k] == a[i]){
    				count++;
    			}
    			else{
    				break;
    			}
    		}
    		if(count == m){
    			int tem = a[i];
    			i += m - 1;
    			a[i] = tem * m;
    		}
    		else{
    			break;
    		}
    	}
    	else if(a[i] > b[j] && a[i] % m == 0 && a[i] / m == b[j]){
    		int count = 0;
    		for(int k = j; k < m; k++){
    			if(b[k] == b[i]){
    				count++;
    			}
    			else{
    				break;
    			}
    		}
    		if(count == m){
    			int tem = b[j];
    			j += m - 1;
    			b[j] = tem * m;
    		}
    		else{
    			break;
    		}

    	}
    	else{
    		break;
    	}
    }
    if(i == n && j == k){
    	cout << "YES" << "\n";
    }
    else{
    	cout << "NO" << "\n";
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