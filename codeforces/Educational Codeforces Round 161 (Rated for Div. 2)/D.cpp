

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
	vector<int> a(n), d(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}

	if(n == 1){
		cout << 0 << "\n";
		return;
	}

	set<int> st;
	for(int i = 0; i < n; i++){
		st.insert(i);
	}

	vector<int> rem;
	for(int i = 0; i < n; i++){
		int sum = 0;
		if(i == 0)
			sum += a[i + 1];
		else if(i == n - 1)
			sum += a[i - 1];
		else{
			sum += a[i - 1];
			sum += a[i + 1];
		}
		if(sum > d[i]){
			rem.push_back(i);
		}
	}

	// debug(rem);

	auto calcdam = [&](int index){
		auto it = st.upper_bound(index);
		auto it2 = st.lower_bound(index);	
		int sum = 0;
		if(it != st.end()){
			int ind = *it;
			sum += a[ind];	
		} 
		if(it2 != st.begin()){
			it2--;
			int ind = *it2;
			sum += a[ind];
		}

		return sum;
	};

	for(int i = 1; i <= n; i++){
		cout << rem.size() << " ";
		for(auto x: rem){
			st.erase(x);
		}
		vector<int> temp;
		set<int> t;
		for(auto x: rem){
			auto it = st.upper_bound(x);
			auto it2 = st.lower_bound(x);
			if(it != st.end()){
				int dm = calcdam(*it);
				if(dm > d[*it])
					t.insert(*it);
			} 
			if(it2 != st.begin()){
				it2--;
				int dm = calcdam(*it2);
				if(dm > d[*it2])
					t.insert(*it2);
			}
		}
		for(auto x: t)
			temp.push_back(x);
		rem.assign(all(temp));
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