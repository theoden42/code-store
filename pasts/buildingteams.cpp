
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

bool colordfs(int source, vector<int>& vis, vector<int>& color, vector<vector<int>>& g){
	vis[source] = 1;
    set<int> st;
    st.insert(1);
    st.insert(2);

	for(auto& x: g[source]){
		if(vis[x]){
            int fd = color[x];
            if(st.find(fd) != st.end()) st.erase(st.find(fd));
        }
	}

    if(st.empty())return false;


    int cls = *(st.begin());
    color[source] = cls;
    for(auto& x: g[source]){
        if(vis[x])continue;

        if(!colordfs(x, vis, color, g)){
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    vector<int> vis(n, 0);
    vector<int> color(n, 0);

    for(int i = 0; i < n; i++){
    	if(!vis[i]){
    		if(!colordfs(i, vis, color, g)){
    			cout << "IMPOSSIBLE\n";
    		}
    	}
    }
    for(int i = 0; i < n; i++){
        cout << color[i] << " ";
    }
    cout << endl;
}	

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}