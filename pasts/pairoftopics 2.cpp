
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

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);

    for(int i = 0; i < n; i++){
    	cin >> vp[i].first;
    }
    for(int i = 0; i < n; i++){
    	cin >> vp[i].second;
    }


    vector<int> diff(n);
    vector<int> ndiff(n);
    for(int i = 0; i < n; i++){
        diff[i] = vp[i].first - vp[i].second;
        ndiff[i] = -1 * diff[i];
    }
    sort(all(diff));
    sort(all(ndiff));
    ll count = 0;
    for(int i = 0; i < n; i++){
        int l = 0;
        int u = n - 1; 
        int index = -1;
        while(l <= u){
            int mid = l + (u - l)/2;
            if(ndiff[mid] < diff[i]){
                index = mid;
                l = mid + 1;
            }
            else{
                u = mid - 1;
            }
        }

        if(diff[i] == 0){
            count += index + 1;
        }
        else if(diff[i] < 0){
            count += index + 1;
        }
        else{
            count += index;
        }

    }
    cout << count/2 << "\n";
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