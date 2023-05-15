
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
    string l1, l2;
    cin >> l1 >> l2;
    map<char,int> mp;
    for(int i = 0; i < l1.size(); i++){
    	mp[l1[i]]++;
    }
    for(int i = 0; i < l2.size(); i++){
    	mp[l2[i]]++;
    }

    if(mp.size() == 1){
    	cout << 0 << "\n";
    }
    else if(mp.size() == 4){
    	cout << 3 << "\n";
    }
    else if(mp.size() == 2){
    	cout << 1 << "\n";
    }
    else if(mp.size() == 3){
    	cout << 2 << "\n";
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