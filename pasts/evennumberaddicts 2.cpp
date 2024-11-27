
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
    vector<int> ele(n, 0);
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
        if(ele[i] & 1){
            odd++;
        }
        else{
            even++;
        }
    }

    if(odd == 0){
        cout << "Alice" << "\n";
        return;
    }
    if(even == 0){
        int val = (odd + 1) / 2;
        if(val & 1)cout << "Bob" << "\n";
        else cout << "Alice" << "\n";

        return;
    }

    if(even & 1){
        //can change the nature of the game
        int val = (odd + 1) / 2;
        if(val & 1){
            // Alice is initially losing here so she may decide to twist the fate of the game, 
            //however she cannot twist the game if the dividing number are even and it doestnot matter who has moved first
            if(odd % 2 == 0){
                cout << "Bob" << "\n";
            }
            else{
                // she succeeds if the number are odd and she would win for sure
                cout << "Alice" << "\n";
            }
        }
        else{
            // Alice is winning and Bob may chose to change the nature of the game, if however we hava already picked and the rest are 
            // even theres no point in who picks first 
            cout << "Alice" << "\n";
        }
    }
    else{
        // cannot change the nature of the game
        int val = (odd + 1) /2 ;
        if(val & 1)cout << "Bob" << "\n";
        else cout << "Alice" << "\n";
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