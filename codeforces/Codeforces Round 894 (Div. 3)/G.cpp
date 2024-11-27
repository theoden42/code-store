

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

    multiset<int> dif;
    multiset<int> values;

    vector temp = a;
   	sort(all(temp));
   	for(int i = 1; i < n; i++){
   		dif.insert(temp[i] - temp[i - 1]);
   	}
   	for(int i = 0; i < n; i++){
   		values.insert(a[i]);
   	}

    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
    	int ind, val;
    	cin >> ind >> val;
    	ind--;

    	if(n == 1){
    		cout << val << "\n";
    		continue;
    	}

    	auto it = values.find(a[ind]);
    	if(it != values.begin()){
    		auto temp = it;
    		--temp;
    		dif.erase(dif.find(*it - *temp));
    	}
    	if(it != --values.end()){
    		auto temp = it;
    		++temp;
    		dif.erase(dif.find(*temp - *it));	
    	}

    	if(it != values.begin() && it != --values.end()){
    		auto temp1 = it;
    		auto temp2 = it;
    		--temp1;
    		++temp2;
    		dif.insert(*temp2 - *temp1);
    	}

    	values.erase(it);
    	it = values.upper_bound(val);
    	if(it == values.end()){
    		auto temp = *(--values.end());
    		dif.insert(val - temp);
    	}
		else if(it == values.begin()){
			auto temp = *values.begin();
			dif.insert(temp - val);
		} else {
			auto temp1 = it;
			temp1--;
			dif.erase(dif.find(*it - *temp1));
			dif.insert(*it - val);
			dif.insert(val - *temp1);
		}

    	a[ind] = val;
    	values.insert(val);	
    	int ans = *(--values.end()) + *(--dif.end());
    	cout << ans << " ";
    }
    cout << "\n";
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