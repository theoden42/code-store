
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
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    ll sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(ele[i] != 0)count++;
    	if(i % 2 == 0){
    		sum += ele[i];
    	}
    	else{
    		sum -= ele[i];
    	}
    }

    if(sum == 0){
        cout << "1\n";
        cout << 1 << " " << n << "\n";
        return;
    }

    if(count & 1){
        cout << "-1\n";
        return;
    }

    vector<pair<int,int>> ans;


    for(int i = 0; i < n; i++){

        int ind1, ind2;
        int j = i;
        while(ele[j] == 0 && j < n)j++;
        ind1 = j;

        if(ele[i] == 0){
            ans.push_back({i + 1, ind1});
            i = ind1 - 1;
            continue;
        }

        j++;
        while(ele[j] == 0 && j < n)j++;
        ind2 = j;

        if(ele[ind1] == ele[ind2]){
            if(ind2 == ind1 + 1){
                ans.push_back({ind1 + 1, ind2 + 1});
            }
            else{
                ans.push_back({ind1 + 1, ind2 - 1});
                ans.push_back({ind2, ind2 + 1});
            }
        }
        else{
            ans.push_back({ind1 + 1, ind2});
            ans.push_back({ind2 + 1, ind2 + 1});
        }
        i = ind2;

    }

    cout << ans.size() << "\n";
    for(auto& x: ans){
        cout << x.first << " " << x.second << "\n";
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