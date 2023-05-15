
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

vector<pair<int,int>> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};


void solve() {
    int n, m, i1, j1, i2, j2;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    string dr;
    cin >> dr;

    map<string, int> mp;
	mp["DR"] = 0;
	mp["DL"] = 1;
	mp["UR"] = 2;
    mp["UL"] = 3;

    map<vector<int>,int> st;

    pair<int,int> d = dir[mp[dr]];
    int x = i1;
    int y = j1;

    int count = 0;

    while(1){
        // debug(x, y);
        vector<int> temp = {x, y, d.first, d.second};
        if(st[temp] == 1){
            cout << "-1\n";
            return;
        }
        if(x == i2 && y == j2){
            cout << count << "\n";
            return;
        }

        st[{x, y, d.first, d.second}] = 1;

        int xt = x + d.first;
        int yt = y + d.second;

        if(xt < 1 && yt < 1){
            count++;
            d.first *= -1;
            d.second *= -1;
            xt = 1; 
            yt = 1;
        }
        else if(xt > n && yt > m){
            count++;
            d.first *= -1;
            d.second *= -1;
            xt = x;
            yt = y;
        }
        else if(xt < 1 && yt > m){
            count++;
            d.first *= -1;
            d.second *= -1;
            xt = x;
            yt = y;

        }
        else if(xt > n && yt < 1){
            count++;
            d.first *= -1;
            d.second *= -1;
            xt = x;
            yt = y;
        }
        else if(xt < 1){
            count++;
            xt = x;
            yt = y;
            d.first *= -1;
        }
        else if(xt > n){
            count++;
            xt = x;
            yt = y;
            d.first *= -1;
        }
        else if(yt < 1){
            count++;
            xt = x;
            yt = y;
            d.second *= -1;
        }
        else if(yt > m){
            count++;
            xt = x;
            yt = y;
            d.second *= -1;
        }
        x = xt;
        y = yt;
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