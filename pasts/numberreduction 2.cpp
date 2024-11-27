
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

    string x;
    cin >> x;
    int k;
    cin >> k;

    int mx = x[0];
    int index = 0;

    for(int i = 0; i <= k; i++){
    	if(x[i] < mx && x[i] != '0'){
    		mx = x[i];
    		index = i;
    	}
    }



   	k = k - index;
   	string temp = "";
    temp += x[index];

    map<int,vector<int>> mp;

    for(int i = index + 1; i < x.size(); i++){
        mp[x[i] - '0'].push_back(i);
    }
    int t = k;


    auto search = [&](vector<int>& v, int in1 , int in2){
        int index = -1;
        int l = 0;
        int r = (int)v.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(v[mid] >= in1 && v[mid] <= in2){
                index = mid;
                r = mid - 1;
            }
            else if(v[mid] < in1){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return index;
    };

    debug(index, t);

    while(k != 0 && index != x.size() - 1){
        debug(k);
        for(int i = 0; i <= 9; i++){
            int pos = search(mp[i], index + 1, index + k + 1);
            debug(pos, mp[i], index + 1, index + k);
            if(pos == -1){
                continue;
            }
            else{
                int ind = mp[i][pos];
                k -= ind - index - 1;
                temp += x[ind];
                index = ind;
                break;
            }
        }
    }
    debug(k);

    for(int i = index + 1; i < x.size(); i++){
        temp += x[i];
    }

    string ans = "";
    for(int i = 0; i < temp.size() - k; i++){
        ans += temp[i];
    }
    cout << ans << "\n";

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