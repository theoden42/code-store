
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
    int n, m;
    cin >> n >> m;
    vector<int> ele1(n, 0);
    vector<int> ele2(m, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele1[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> ele2[i];
    }
    vector<int> fin(n + m, 0);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m){
    	if(ele1[i] < ele2[j]){
    		fin[k++] = ele1[i];
    		i++;
    	}
    	else{
    		fin[k++] = ele2[j];
    		j++;
    	}
    }
    while(i < n || j < m){
    	if(i < n){
    		fin[k++] = ele1[i];
    		i++;
    	}
    	else{
    		fin[k++] = ele2[j];
    		j++;
    	}
    }
    for(auto& x: fin){
    	cout << x << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    ///cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}