
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
    int c1 = 0;
    int c2 = 0;
    int c0 = 0;


    for(int i = 0; i < n; i++){
        if(ele[i] != i + 1 && ele[i] != n - i){
            c0++;
        }

        else if(ele[i] != i + 1)c1++;
        else if(ele[i] != n - i)c2++;

    }


    if(c1 == 0 && c2 == 0){
        cout << "Tie\n";
        return;
    }

    else if(c1 == 0){
        if(c2 >= c0){
            cout << "First\n";

        }
        else{
            cout << "Tie\n";
        }
    }
    else if(c2 == 0){
        if(c1 > c0){
            cout << "Second\n";
        }   
        else{
            cout << "Tie\n";
        }
    }

    else{
        if(c1 > c2){
            if(c1 - c2 > c0){
                cout << "Second\n";
            }
            else{
                cout << "Tie\n";
            }
        }      
        else{
            if(c2 - c1 >= c0){
                cout << "First\n";
            }
            else{
                cout << "Tie\n";
            }
        }
    }
    debug(c0, c1, c2);


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