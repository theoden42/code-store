
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
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> t(n);
    for(int i = 0; i < n; ++i){
    	cin >> t[i];
    }
    sort(all(t));

    int count = 0;

    for(int i = 0; i < n; i++){
    	count++;
   		int time = t[i] + w; // time untill i can vaccinate this person
   		int l_time = time + d; // time after which the doses are unusable;
   		

   		int l = i;
   		int u = n - 1;
   		int ind = i;
   		while(l <= u){
   			int mid = (l + u) / 2;
   			if(t[mid] <= l_time){
   				ind = mid; 
   				l = mid + 1;
   			}
   			else{
   				u = mid - 1;
   			}
   		}

   		int num = min(k, ind - i + 1);	
   		i += num - 1;
    }

    cout << count << "\n";
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