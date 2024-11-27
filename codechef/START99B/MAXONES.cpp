

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
   	string s;
   	cin >> s;

   	vector<int> ans(n, 0);
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << s << endl;
        return;
    }

    flag = 1;
    for(int i = 1; i < n - 1; i++){
        int a = s[i - 1] - '0';
        int b = s[i] - '0';
        int c = s[i + 1] - '0';
        if((a ^ c) != b){
            flag = 0;
            break;
        }
    }
    if(flag){
        cout << s << endl;
        return;
    }

    ans[0] = s[0] - '0';
    ans[n - 1] = s[n - 1] - '0'; 
    if(s[0] == '0' || s[n - 1] == '0'){
        for(int i = 1; i < n - 1; i++){
            ans[i] = 1;
        }
    }else{
        int ind = -1;
        for(int i = 1; i < n - 1; i++){
            if(s[i] != '1'){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            cout << s << endl;
            return;
        }
        int numones = ind;
        if(numones > 2){
            ans[0] = 1;
            for(int i = 2; i < n; i++){
                ans[i] = 1;
            }
        }else{
            for(int i = 0; i < n; i++){
                if(i == 1)
                    continue;
                ans[i] = 1;
            }
        }
    }


   	for(auto x: ans){
   		cout << x;
   	}
   	cout << endl;
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