
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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    vector<int> firsm;
    multiset<int> current;
    multiset<int> viable;

    ll sum = 0;

   	for(int i = 0; i < m; i++){
   		firsm.push_back(ele[i]);
   	}

   	sort(all(firsm));

   	debug(firsm);

   	for(int i = 0; i < k; i++){
   		current.insert(firsm[i]);
   		sum += firsm[i];
   	}	
   	for(int i = k; i < m; i++){
   		viable.insert(firsm[i]);
   	}

   	debug(current, viable);

   	cout << sum << " ";

   	for(int i = 0; i <= n - m - 1; i++){
   		int old = ele[i];
   		int newval = ele[i + m];
   		debug(old, newval);

   		viable.insert(newval);
   		if(current.find(old) != current.end()){
   			sum -= old;
   			current.erase(current.find(old));
   			auto it = viable.begin();
   			sum += *it;
            current.insert(*it);
   			viable.erase(it);
   		}
   		else{
            if(viable.find(old) != viable.end())
   			  viable.erase(viable.find(old));


   			if(*viable.begin() < *(--current.end())){
   				sum = sum - *(--current.end()) + *viable.begin();

   				int temp = *viable.begin();
   				int temp2 = *(--current.end());
   				viable.erase(viable.find(temp));
   				current.erase(current.find(temp2));

   				viable.insert(temp2);
   				current.insert(temp);

   			}
   		}

   		debug(current, viable);
   		cout << sum << " ";
   	}
   	cout << "\n";

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