
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

bool can_reduce(int val, int lb, int ub, int k){
	int l = 1;
	int u = k;
	int ans = -1;
	while(l <= u){
		int mid = l + (u - l) / 2;
		int temp = val / mid;
		if(temp >= lb){
			if(temp <= ub){
				ans = mid;
				break;
			}
			else{
				l = mid + 1;
			}
		}
		else{
			u = mid - 1;
		}
	}
	if(ans != -1)return true;
	else return false;
}


bool check(vector<int>& ele, int gap, int k){
	int n = ele.size();
	for(int i = 1; i <= ele[0]; ++i){
		int flag = 1;
		for(int j = 0; j < n; j++){
			if(can_reduce(ele[j], i, i + gap, k)){
				continue;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag){
			debug(gap, i);
			return true;
		}
	}
	return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ele(n);
    for(int i = 0; i < n; ++i){
    	cin >> ele[i];
    }

    int l = 0;
    int u = 3000;
    int ind = ele[n - 1] - ele[0];
    while(l <= u){
    	int mid = l + (u - l) / 2;
    	if(check(ele, mid, k)){
    		ind = min(ind, mid);
    		u = mid - 1;
    	}
    	else{
    		l = mid + 1;
    	}
    }
    cout << ind << "\n";

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