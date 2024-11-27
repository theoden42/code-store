
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
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    int f = 1;
    for(int i = 0; i < n; ++i){
    	if(ele[i] != ele[0]){
    		f = 0;
    		break;
    	}
    }


    if(f){
    	cout << 0 << "\n";
    	return;
    }


    for(int i = 0; i < n; i++){
    	if(ele[i] == 1){
    		cout << "-1\n";
    		return;
    	}
    }

    vector<pair<int,int>> nele(n);
    for(int i = 0; i < n; i++){
    	nele[i] = {ele[i], i + 1};
    }


    vector<pair<int,int>> vp;

    while(vp.size() <= 30 * n){
    	sort(all(nele));
    	int x = nele[0].first;
    	int y = nele[0].second;
    	for(int i = 1; i < n; i++){
    		while(nele[i].first > x){
    			nele[i].first = (nele[i].first + x - 1) / x;
    			vp.push_back({nele[i].second, y});
    		}
    	}
    	int f = 1;
    	for(int i = 0; i < n; i++){
    		if(nele[i].first != nele[0].first){
    			f = 0;
    			break;
    		}
    	}
        if(f)break;
    }

    f = 1;
	for(int i = 0; i < n; i++){
		if(nele[i].first != nele[0].first){
			f = 0;
			break;
		}
	}
	assert(f == 1);

    cout << vp.size() << "\n";
    for(int i = 0; i < vp.size(); i++){
    	cout << vp[i].first << " " << vp[i].second << "\n";
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