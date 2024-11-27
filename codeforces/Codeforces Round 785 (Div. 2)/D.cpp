

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

#define int long long


int present(int ele, int start, int diff, int term){
	int x = ele - start; 
	if(x < 0 || x % diff != 0)return false;
	int num = x / diff;
	if(num >= term)return false;

	return true;
}

void solve() {
    int b, q, y;
    cin >> b >> q >> y;
    int c, r, z;
    cin >> c >> r >> z;
    if(r % q != 0 || !present(c, b, q, y)){
    	cout << "0\n";
    	return;
    }

    int lastc = c + (z - 1) * r;
    int lastb = b + (y - 1) * q;

    if(lastc > lastb){
        cout << "0\n";
        return;
    }
    if(!present(lastc + r, b, q, y) || !present(c - r, b, q, y)){
        cout << "-1\n";
        return;
    }

    int count = 0;

    auto check = [&](int fact)->int{
        int l = lcm(fact, q);
        if(l != r) return 0;
        int temp = 0;
        // first element to match is c ? how many elements can there be which are starting elements 
        temp += (r / fact) % MOD;
        temp *= (r / fact) % MOD;
        return temp;
    };


    for(int i = 1; i * i <= r; i++){
        if(r % i == 0){
            int f1 = i;
            int f2 = r / i; 
            if(f1 == f2){
                count += check(f1);
                count %= MOD;
            }
            else{
                count += check(f1);
                count %= MOD;
                count += check(f2);
                count %= MOD;
            }
        }
    }

    cout << count << "\n";


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