

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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	int t1 = max(a[0], b[0]);
	int t2 = max(a[1], b[1]);
	int m1, m2;
	m1 = max(t1, t2);
	m2 = min(t1, t2);	

	auto change = [&](int m1, int m2, int c){
		multiset<int> mst;	
		mst.insert(m1);mst.insert(m2);mst.insert(c);
		return make_pair(*prev(mst.end(), 1), *prev(mst.end(), 2));
	};

	int count = 0;
	for(int i = 2; i < n; i++){
		int s = m1 + m2;
		if(a[i] <= s && b[i] <= s){
			count += 1;
			auto p = change(m1, m2, max(a[i], b[i]));
			m1 = p.first;
			m2 = p.second;
		} else if(a[i] > s && b[i] > s){
			auto p = change(m1, m2, max(a[i], b[i]));
			m1 = p.first;
			m2 = p.second;
		} else {
			auto [n1, n2] = change(m1, m2, max(a[i], b[i]));
			auto [p1, p2] = change(m1, m2, min(a[i], b[i]));	
			int ind1 = n, ind2 = n;
			for(int j = i + 1; j < n; j++){
				if(min(a[j], b[j]) > n1 + n2){
					ind1 = j;
					break;
				}
			}
			for(int j = i + 1; j < n; j++){
				if(min(a[j], b[j]) > p1 + p2){
					ind2 = j;
					break;
				}
			}
			if(ind2 + 1 < ind1){
				m1 = n1, m2 = n2;
			} else {
				count += 1;
				m1 = p1, m2 = p2;
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