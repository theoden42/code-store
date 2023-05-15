
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

void makequery(int l, int r){
	cout << "? " << l << " " << r << endl;
}

void solve() {
    int n;
    cin >> n;
	int l = 1;
	int r = n;
	while(l <= r){
		if(l == r){
			makequery(l, r);
			int x;
			cin >> x;
			cout << "! " << x << endl;
			return;
		}
		int mid = l + (r - l)/2;
		makequery(l, mid);
		vector<int> ele(mid - l + 1);
		int count = 0;
		for(int i = 0; i < mid - l + 1; i++){
			cin >> ele[i];
			if(ele[i] >= l && ele[i] <= mid){
				count++;
			}
		}
		if(count % 2 == 0){
			l = mid + 1;
		}
		else{
			r = mid;
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