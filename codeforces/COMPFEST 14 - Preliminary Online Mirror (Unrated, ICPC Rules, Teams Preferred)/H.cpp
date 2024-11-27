

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    map<int,int> mp;

    for(int i = 0; i < n; i++){
    	int x = (a[i] % 3);
    	int y = (x * x) % 3;
    	a[i] = y;
    	mp[y]++;
    }

    vector<int> ans(n, -1);
    int f = 0;

    if(mp[0] == n){
        cout << 1 << "\n";
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                ans[i] = 0;
            }
            else{
                ans[i] = 1;
            }
        }
        f = 1;
    }
    else if(mp[1] == n){
        cout << 1 << "\n";
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                ans[i] = 0;
            }
            else{
                ans[i] = 1;
            }
        }
        f = 1;
    }
    else if(mp[2] == n){
        cout << 0 << "\n";
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                ans[i] = 0;
            }
            else{
                ans[i] = 1;
            }
        }
        f = 1;
    }

    else if(mp[0] == 0){
        f = 1;
        if(mp[1] > mp[2]){
            cout << 1 << "\n";
            int count = 0;
            for(int i = 0; i < n && count < n / 2; i++){
                if(a[i] == 1){
                    ans[i] = 0;
                    count++;
                }
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == -1){
                    ans[i] = 1;
                }
            }
        }
        else{
            cout << 2 << "\n";
            int count = 0;
            for(int i = 0; i < n && count < n / 2; i++){
                if(a[i] == 2){
                    ans[i] = 0;
                    count++;
                }
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == -1){
                    ans[i] = 1;
                }
            }
        }

    }
    else if(mp[1] == 0){
        f = 1;
        if(mp[2] > mp[0]){
            cout << 0 << "\n";
            int count = 0;
            for(int i = 0; i < n && count < n / 2; i++){
                if(a[i] == 2){
                    ans[i] = 0;
                    count++;
                }
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == -1){
                    ans[i] = 1;
                }
            }
        }
        else{
            cout << 1 << "\n";
            int count = 0;
            for(int i = 0; i < n && count < n / 2; i++){
                if(a[i] == 0){
                    ans[i] = 0;
                    count++;
                }
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == -1){
                    ans[i] = 1;
                }
            }
        }

    }
    else if(mp[2] == 0){
        f = 1;

        if(mp[1] > mp[0]){
            cout << 0 << "\n";
            int count = 0;
            for(int i = 0; i < n && count < n / 2; i++){
                if(a[i] == 1){
                    ans[i] = 0;
                    count++;
                }
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == -1){
                    ans[i] = 1;
                }
            }
        }
        else{
            cout << 2 << "\n";
            int count = 0;
            for(int i = 0; i < n && count < n / 2; i++){
                if(a[i] == 0){
                    ans[i] = 0;
                    count++;
                }
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == -1){
                    ans[i] = 1;
                }
            }
        }
    }
    else{
        for(int i = 0; i < 3; i++){
            if(i == 0 && (mp[0] == mp[1] + mp[2])){
                cout << 0 << "\n";
                for(int i = 0; i < n; i++){
                    if(a[i] == 0){
                        ans[i] = 1;
                    }
                    else{
                        ans[i] = 0;
                    }
                }
                f = 1;
            }
            else if(i == 1 && (mp[2] == mp[0] + mp[1])){
                cout << 1 << "\n";
                for(int i = 0; i < n; i++){
                    if(a[i] == 2){
                        ans[i] = 1;
                    }
                    else{
                        ans[i] = 0;
                    }
                }
                f = 1;
            }
            else if(i == 2 && (mp[1] == mp[0] + mp[2])){
                cout << 2 << "\n";
                for(int i = 0; i < n; i++){
                    if(a[i] == 1){
                        ans[i] = 1;
                    }
                    else{
                        ans[i] = 0;
                    }
                }
                f = 1;
            }
        }
    }

    if(!f){
    	cout << "-1\n";
    	return;
    }

    for(auto x: ans){
    	cout << x;
    }

    cout << "\n";


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