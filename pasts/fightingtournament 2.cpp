
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
	int n, q;
	cin >> n >> q;
	vector<int> ele(n, 0);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}
	int ind = 0;
	for(int i = 0; i < n; i++){
		if(ele[i] == n){
			ind = i;
			break;
		}
	
	}
	vector<int> winner(n, 0);
	int mx = ele[0];
	if(ele[1] > ele[0]){
		winner[0] = 1;
		winner[1] = 1;
		mx = ele[1];
	}
	else{
		winner[0] = 0;
		winner[1] = 0;
		mx = ele[0];
	}
	for(int i = 2; i < n; i++){
		if(ele[i] > mx){
			mx = ele[i];
			winner[i] = i;
		}
		else{
			winner[i] = winner[i - 1];
		}
	}
	// cout << ind << "\n";
	for(int i = 1; i <= q; i++){
		int j, k;
		cin >> j >> k;
		j--;
		if(k < j){
			cout << 0 << "\n";
			continue;
		}
		if(j > ind){
			cout << 0 << "\n";
			continue;
		}
		else if(j == ind){
			if(ind == 0 || ind == 1){
				cout << k << "\n";
			}
			else{
				cout << k - ind + 1 << "\n";
			}
		}
		else{
			if(winner[j] != j)
				cout << 0 << "\n";
			else{
				int l = j;
				int u = ind;
				int index2 = l;
				while(l <= u){
					int mid = l + (u - l) / 2;
					if(winner[mid] != j){
						u = mid - 1;
					}
					else{
						index2 = mid;
						l = mid + 1;
					}
				}
				if(j == 0)
					cout << min(index2, k) << "\n";
				else
					cout << min(index2 - j, k - j) + 1 << "\n";
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