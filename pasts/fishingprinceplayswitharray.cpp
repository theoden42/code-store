
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define int long lon

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k, 0);
    for(int i = 0; i < k; i++){
    	cin >> b[i];
    }

    ll sum1 = 0;
    ll sum2 = 0;
    sum1 = accumulate(all(a), sum1);
    sum2 = accumulate(all(b), sum2);
    if(sum1 != sum2){
        cout << "NO\n";
        return;
    }

    vector<pair<int,int>> temp_a;
    int i = 0;

    while(i < n){
        int temp = a[i];

        while(temp % m == 0){
            temp = temp / m;
        }

        temp_a.push_back({temp, a[i] / temp});
        i++;
    }

    vector<pair<int,int>> temp_b;
    int j = 0;
    while(j < k){
        int temp = b[j];
        while(temp % m == 0){
            temp /= m;
        }
        temp_b.push_back({temp, b[j] / temp});
        j++;
    }

    debug(temp_a, temp_b);

    vector<pair<int,int>> new_a;
    vector<pair<int,int>> new_b;
    new_a.push_back(temp_a[0]);
    int l = 0;
    for(int i = 1; i < n; i++){
        if(temp_a[i].first == new_a[l].first){
            new_a[l].second += temp_a[i].second;
        }
        else{
            new_a.push_back(temp_a[i]);
            l++;
        }
    }
    debug(new_a);

    new_b.push_back(temp_b[0]);
    l = 0;
    for(int j = 1; j < k; j++){
        if(temp_b[j].first == new_b[l].first){
            new_b[l].second += temp_b[j].second;
        }
        else{
            new_b.push_back(temp_b[j]);
            l++;
        }
    }
    debug(new_b);
    if(new_b.size() != new_a.size()){
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < new_a.size(); i++){
        if(new_a[i] != new_b[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}