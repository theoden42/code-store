
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
    vector<int> pos;
    vector<int> negs;
    for(int i = 0; i < n; i++){
    	if(ele[i] > 0)pos.push_back(ele[i]);
    	else negs.push_back(-1 * ele[i]);
    }

    sort(all(pos));
    sort(all(negs));
   	ll sum = accumulate(all(negs), 0ll);
   	sum += accumulate(all(pos), 0ll);

   	if(negs.size() % 2 == 0){
   		cout << sum << "\n";
   		return;
   	}

   	if(pos.size() > 0){
   		cout << max(sum - 2 * pos[0], sum - 2 * negs[0]) << "\n";
   		return;
   	}
   	cout << sum - 2 * negs[0] << "\n";

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