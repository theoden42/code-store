
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
   int n, m;
   cin >> n >> m;
   vector<int> ele(n);
   map<int,int> mp;
   for(int i = 0; i < n; i++){
   	cin >> ele[i];
   	mp[ele[i]] = i;
   } 

   mp[0] = -1;
   mp[n + 1] = n + 1;

   vector<int> pr(n + 2, 0);

   for(int i = 0; i < n; i++){
   		if(mp[ele[i] - 1] < mp[ele[i]]){
   			pr[ele[i]] = 1;
   		}
   }
   pr[n + 1] = 1;

   int sum = accumulate(all(pr), 0);


   auto doval = [&](int t1){
   		// debug(t1, pr[t1], mp[t1], mp[t1 - 1]);
	   	if(pr[t1] && mp[t1] < mp[t1 - 1]){
	   		pr[t1] = 0;
	   		sum--;
	   	}

	   	if(!pr[t1] && mp[t1] > mp[t1 - 1]){
	   		pr[t1] = 1;
	   		sum++;
	   	}

	   	if(pr[t1 + 1] && mp[t1 + 1] < mp[t1]){
	   		pr[t1 + 1] = 0;
	   		sum--;
	   	}

	   	if(!pr[t1 + 1] && mp[t1] < mp[t1 + 1]){
	   		pr[t1 + 1] = 1;
	   		sum++;
	   	}
	   	debug(pr);
   };

   for(int i = 1; i <= m; i++){
	   	int a, b;
	   	cin >> a >> b;
	   	a--;
	   	b--;



	   	int t1 = ele[a];
	   	int t2 = ele[b];



	   	mp[t1] = b;
	   	mp[t2] = a;
	   	swap(ele[a], ele[b]);



	   	doval(max(t1, t2));
	   	doval(min(t1, t2));



	   	cout << n - sum + 2 << "\n";
   	}

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