
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int ulog(int n){
	int count = 0;
	int onecount = 0;
	while(n != 0){

		if(n & 1)onecount++;

		count++;
		n >>= 1;
	}

	if(onecount == 1){
		return count - 1;
	}
	else{
		return count;
	}

}

void solve() {
    int n, ival;
    cin >> n >> ival;

    int bits = ival * 8;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    sort(all(ele));

    map<int, int> mp;


    int j = 0;
    int mx = 0;

    debug(ele);

    for(int i = 0; i < n; i++){
        while(j < n){
            if(mp.find(ele[j]) != mp.end()){
                mp[ele[j]]++;
                j++;
                continue;
            }
            else{
                if(ceil(log2(mp.size() + 1.0)) * n > bits){
                    break;
                } 
                else{
                    mp[ele[j]]++;
                    j++;
                    continue;
                }
            }
        }   
        debug(i, j, mp.size(), mp);

        mx = max(mx, j - i);
        mp[ele[i]]--;
        if(mp[ele[i]] == 0)mp.erase(ele[i]);
    }

    cout << n - mx << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}