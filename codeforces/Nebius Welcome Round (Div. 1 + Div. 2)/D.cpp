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
    vector<vector<int>> gr(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        for(int j = 0; j < m; j++){
            gr[i][j] = x[j] - '0';
        }
    }

    int cmin = 0, cmax = 0;

    auto getmax = [&](vector<int>& g){

        int c1 = m / 2;
        int c2 = m / 4;

        int count = 0;
        int mx = 0;

        for(auto x: g){
            if(x == 1)mx++;
        }

        for(int i = 0; i < g.size() - 1; i += 1){
            if(g[i] == 0 || g[i + 1] == 0){
                count++;
                i++;
            }
        }   

        int temp = mx - (m / 4 - min(m / 4, count));

        debug(temp);
        return temp;

    };



    auto getmin = [&](vector<int>& g){
        int c1 = m / 2;
        int c2 = m / 4;
        int temp = 0;

        for(int i = 0; i < g.size(); i++){
            if(g[i] == 0)continue;

            int j = i;
            int count = 0;
            for(; j < g.size(); j++){
                if(g[j] == 1)count++;
                else{
                    break;
                }
            }

            int t = min(c2, (count / 2));
            temp += t;
            c2 -= min(c2, (count / 2));
            temp += (count - 2 * t);
            i = j - 1;
        }

        return temp;    
    };

    for(int i = 0; i < n; i++){
        cmax += getmax(gr[i]);
        cmin += getmin(gr[i]);
    }

    cout << cmin << " " << cmax << endl;

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