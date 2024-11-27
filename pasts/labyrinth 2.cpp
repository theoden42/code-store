
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

vector<pair<int,int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs(int i, int j, vector<vector<char>>& grid, int n, int m){

    queue<pair<int, int>> q;
    q.push({i, j});
    map<pair<int,int>, char> mp;
    string move = "ULDR";

    int rowans = -1;
    int colans = -1;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(grid[a][b] == 'B'){
            rowans = a;
            colans = b;
            break;
        } 

        for(int i = 0; i < 4; i++){
            pair<int,int> d = dir[i];
            int row = a + d.first;
            int col = b + d.second;
            if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] != '#' && !vis[row][col]){
                mp[{row, col}] = move[i];
                vis[row][col] = 1;
                q.push({row, col});
            }
        }
    }

    if(rowans == -1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    string ans = "";


    while(rowans != i || colans != j){
        char ch = mp[{rowans, colans}];
        ans += ch;
        if(ch == 'U'){
            rowans += 1;
        }
        else if(ch == 'L'){
            colans += 1;
        }
        else if(ch == 'R'){
            colans -= 1;
        }
        else{
            rowans -= 1;
        }
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    cout << ans << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < m; j++){
    		grid[i][j] = s[j];
    	}
    }
    int ind1 = 0;
    int ind2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                ind1 = i;
                ind2 = j;
                break;
            }
        }
    }


    bfs(ind1, ind2, grid, n, m);

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