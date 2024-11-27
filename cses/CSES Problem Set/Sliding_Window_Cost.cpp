

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
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	} 

	if(k == 1){
		for(int i = 0; i < n; i++)
			cout << "0 ";
		cout << "\n";
		return;
	}

	vector<int> temp;
	for(int i = 0; i < k; i++){
		temp.push_back(v[i]);
	}
	sort(all(temp));

	int lsum = 0;
	int rsum = 0;
	multiset<int> left, right;
	for(int i = 0; i <= (k - 1) / 2; i++){
		left.insert(temp[i]);
		lsum += temp[i];
	}	
	for(int i = (k - 1) / 2 + 1; i < k; i++){
		right.insert(temp[i]);
		rsum += temp[i];
	}

	auto dofix = [&](){
		if(*(--left.end()) > *right.begin()){
			auto t1 = *(--left.end());
			auto t2 = *right.begin();
			left.erase(--left.end());
			right.erase(right.begin());
			lsum += -t1 + t2;
			rsum += t1 - t2;
			left.insert(t2);
			right.insert(t1);
		}
	};	

	int med = *(--left.end());
	int ltemp = med * ((k - 1)/ 2 + 1);
	int rtemp = med * (k - (k - 1) / 2 - 1);
	int total = ltemp - lsum + rsum - rtemp;
	cout << total << " ";

	for(int i = 0; i < n - k; i++){
		if(left.find(v[i]) != left.end()){
			left.erase(left.find(v[i]));
			lsum -= v[i];
			left.insert(v[i + k]);
			lsum += v[i + k];
		} else {
			right.erase(right.find(v[i]));
			rsum -= v[i];
			right.insert(v[i + k]);
			rsum += v[i + k];
		}
		debug(left, right);
		dofix();
		int med = *(--left.end());
		int ltemp = med * ((k - 1) / 2 + 1);
		int rtemp = med * (k - (k - 1)/ 2 - 1);
		int total = ltemp - lsum + rsum - rtemp;
		cout << total << " ";
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