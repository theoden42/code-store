
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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    vector<int> index(n, 0);

    cout << "YES" << "\n";
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < m; i++){
    	index[i] = i + 1;
    	pq.push({ele[i], i + 1});
    }
    for(int i = m; i < n; i++){
    	int x1 = (pq.top()).second;
    	int y1 = ele[i] + (pq.top()).first;
    	index[i] = x1;
    	debug(i, x1, y1);
    	pq.pop();
    	pq.push({y1, x1});
    }
    for(int i = 0; i < n; i++){
    	cout << index[i] << " ";
    }
    cout << "\n";
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