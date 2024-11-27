

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> num;
int DP[10][2][2];
int D;	
int call(int pos, int cnt, int f){
    if(pos == num.size()){
        return cnt;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        LMT = num[pos];
    } else {
        LMT = 9;
    }

    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1;
        if(dgt == D) ncnt = 1;
        res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int isgood(int n, int d) {
	num.clear();
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				DP[i][j][k] = -1;
			}
		}
	}
	D = d;
	while(n) {
		num.push_back(n%10);
		n/=10;
	}

	reverse(num.begin(), num.end());

	return call(0, 0, 0);
};

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int x = (a + b - 1)/b;

    int l = x, r = 2e9;
    while(l < r) {
    	int mid = l + (r-l)/2; 
    	if(isgood(mid, c) >= x) {
    		r = mid;	
    	} else {
    		l = mid+1;
    	}
    }

    cout << l << endl;
}
	

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}	