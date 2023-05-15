
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

    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    int mx = 1;
    vector<int> ans(n);
    map<int,int> mp;

    int count = 1;

    for(int i = 0; i < n; i++){
		for(int j = 0; j < p.size(); j++){
			if(ele[i] % p[j] == 0){
                if(mp.find(p[j]) == mp.end()){
                    mp[p[j]] = count;
                    ans[i] = mp[p[j]];
                    count++;
                }
                else{
                    ans[i] = mp[p[j]];
                }
                break;
			}
		}
    }

    cout << mp.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
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