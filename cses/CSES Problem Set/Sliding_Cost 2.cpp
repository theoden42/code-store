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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	if(k == 1){
		for(int i = 0; i < n; i++){
			cout << 0 << " ";
		}
		return;
	}


	ordset<pair<int,int>> st;
	for(int i = 0; i < k; i++){
		st.insert({a[i], i});
	}

	ll sum = 0;
	ll sum2 = 0;



	if(k & 1){
		for(int i = 0; i <= k / 2; i++){
			sum += st.find_by_order(i)->first;
		}
		for(int i = k / 2 + 1; i < k; i++){
			sum2 += st.find_by_order(i)->first;
		}
	}
	else{
		for(int i = 0; i < k / 2; i++){
			sum += st.find_by_order(i)->first;
		}
		for(int i = k / 2; i < k; i++){
			sum2 += st.find_by_order(i)->first;
		}
	}


	for(int i = 0; i <= n - k; i++){

		debug(st, sum, sum2);

		int md = st.find_by_order(k / 2) -> first;

		if(k & 1){
			cout << sum2 - sum + md << " ";
		}
		else{
			cout << sum2 - sum << " ";
		}


		if(i == n - k)continue;

		int ad = a[i + k];
		int rm = a[i];

		if(k & 1){
			int md2 = st.find_by_order(k / 2 + 1)->first;

			st.erase({rm, i});
			st.insert({ad, i + k});

			if(rm <= md && ad <= md){
				sum += (ad - rm);
			}
			else if(rm > md && ad > md){
				sum2 += (ad - rm);
			}
			else if(rm <= md && ad > md){
				sum += (md2 - rm);
				sum2 += (ad - md2);
			}
			else{
				sum += (ad - md);
				sum2 += (md - rm);
			}
		}
		else{
			md = st.find_by_order(k / 2 - 1)->first;
			int md2 = st.find_by_order(k / 2)->first;

			int k1 = st.order_of_key({rm, i});
			st.erase({rm, i});
			st.insert({ad, i + k});
			int k2 = st.order_of_key({ad, i + k});


			debug(rm, ad, md, md2);
			if(k1 < k / 2 && k2 < k / 2){
				sum += (ad - rm);
			}
			else if(k1 >= k / 2 && k2 >= k / 2){
				sum2 += (ad - rm);
			}
			else if(k1 < k / 2 && k2 >= k / 2){
				sum += (md2 - rm);
				sum2 += (ad - md2);
			}
			else{
				sum += (ad - md);
				sum2 += (md - rm);
			}
		}



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