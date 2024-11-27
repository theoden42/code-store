
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

bool check(string s, int val, vector<int> one, vector<int> zeros){
    int n = one.size() - 1;
    for(int i = 0; i < n; i++){
        int l = i;
        int u = n - 1;
        int index = -1;
        while(l <= u){
            int mid = l + (u - l)/2;
            if(zeros[mid + 1] - zeros[i] <= val){
                index = mid;
                l = mid + 1;
            }
            else{
                u = mid - 1;
            }
        }
        if(index == -1){
            continue;
        }
        if(one[n] - (one[index + 1] - one[i]) > val){
            continue;
        }
        else{
            return true;
        }
    }
    return false;
}


void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> one(n + 1, 0);
    vector<int> zero(n + 1, 0);
    one[0] = 0;
    zero[0] = 0;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '0'){
            zero[i] = zero[i - 1] + 1;
            one[i] = one[i - 1];
        }
        else{
            zero[i] = zero[i - 1];
            one[i] = one[i - 1] + 1;
        }
    }
    if(one[n] == 0){
        cout << 0 << "\n";
        return;
    }
    // for(int i = 0; i <= n; i++){
    //     cout << one[i] << " ";
    // }
    // cout << '\n';
    int l = 0;
    int u = max(zero[n], one[n]); 
    int index = u;
    while(l <= u){
        int mid = l + (u - l)/2;
        // cout << mid << ",,\n";
        if(check(s, mid, one, zero)){
            index = mid;
            u = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }  
    cout << index << "\n";     
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