
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ele(k);
    for(int i = 0; i < k; i++){
    	cin >> ele[i];
    }

    int count = k;
    int left = n * m - 4;
    multiset<int> mst;

    for(int i = 0; i < k; i++){
    	if(ele[i] == count){
    		count--;
    		while(!mst.empty() && *(--mst.end()) == count){
    			mst.erase(--mst.end());
    			left++;
    			count--;
    		}
    	}
    	else{
    		if(left > 0){
    			left--;
    			mst.insert(ele[i]);
    		}
    		else{
    			cout << "Tidak\n";
    			return;
    		}
    	}
    }
    cout << "YA\n";
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