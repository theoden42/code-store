
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

#ifndef ONLINE_JUDGE
    #include <debug.h>
#else
    #define debug(...)
#endif

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

bool comparefn(pair<string,int> a, pair<string,int> b){
    return a.first.size() >= b.first.size();
}

void solve() {
 	string s;
 	cin >> s;
 	int n;
 	cin >> n;
 	vector<string> ele(n);
 	for(int i = 0; i < n; i++){
        cin >> ele[i];
 	}
    vector<int> color((int)s.size(), 0);
    vector<pair<int,int>> ans;

    debug(s, ele, color, ans);


    auto checkuncolored = [&](int x, int y){
        for(int i = x; i <= y; i++){
            if(color[i] != 1){
                return 1;
            }
        }
        return 0;
    };

    auto ispresent = [&](string& chk){
        for(int i = 0; i < n; i++){
            if(ele[i] == chk){
                return i;
            }
        }
        return -1;
    };

    auto paint = [&](int x, int y){
        for(int i = x; i <= y; i++){
            color[i] = 1;
        }
    };  

    auto ispresentassuffix = [&](int val1, int val2){
        for(int i = 0; i < n; i++){
            int l = ele[i].size();
            if(val2 - l + 1 <= val1 && val2 - l + 1 >= 0){
                if(ele[i] == s.substr(val2 - l + 1, l)){
                    return i;
                }
            }
        }
        return -1;
    };

    int count = 0;

    int len = s.size();

    for(int i = 0; i < len; i++){
        int j = 0;
        for(j = min(i + 9, len - 1); j >= i; j--){
            int x = ispresentassuffix(i, j);
            if(x == -1){
                continue;
            }
            else{
                count++;
                ans.push_back({x, j - ele[x].size() + 1});
                i = j;
                break;
            }
        }
        if(j == i - 1){
            debug(i);
            cout << "-1" << "\n";
            return;
        }
    }
    cout << count << "\n";
    for(auto& y: ans){
        cout << y.first + 1 << " " << y.second + 1 << "\n";
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