

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


int k;
string s;

template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden = 0;
    int totallevel = 0;
   
	T combine(T a, T b, char val){
       	if(val == '0')
       		return a;
       	else if(val == '1')
       		return b;
       	else return a + b;

 	}
 	T single_value(int v, int x){
    	if(s[get_ind(x)] == '?')
    		return 2;
    	else
    		return 1;
 	}
    
	void init(int n, int tot){
		while(sz < n){
			sz *= 2;
		}
		totallevel = tot;
		arr.resize(2 * sz, iden);
	}

	int get_ind(int x){
		x += 1;
		int count = 0;
		int level = 1;
		while(level <= x){
			level *= 2;
			count += 1;
		}

		int leftnodes = ((1 << totallevel) - (1 << count));	
		int ind = leftnodes + (x - (1 << (count - 1)));
		return ind;
	}

	int get_x(int ind){
		int height = 0;
		int values = 1 << (k - 1);
		int sum = 0;
		int count = 0;
		while(sum + values < ind){
			sum += values;
			values /= 2;
			count += 1;
		}

		int x = (1 << (totallevel - count)) - 1 - (sum + values - ind);
		return x - 1;
	}

	void build(vector<int>& a){
		build(a, 0, 0, sz);
	}

	void set(int ind){
		int x = get_x(ind + 1) + 1;
		while(x != 0){
			int left = 2 * (x - 1) + 1;
			int right = 2 * (x - 1) + 2;
			if(left < 2 * sz - 1){
				arr[x - 1] = combine(arr[left], arr[right], s[get_ind(x - 1)]);
			}
			else {
				arr[x - 1] = single_value(1, x - 1);
			}
			x /= 2;
		}	
	}

	T get(){
		return arr[0];	
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				arr[x] = single_value(a[lx], x);
			}	
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2], s[get_ind(x)]);
	}

};


void solve() {
    cin >> k;
    cin >> s;

    int n = (1 << (k - 1));
    vector<int> v(n, 1);
    SegTree<int> st;
    st.init(n, k);	
    st.build(v);

    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
    	int ind;
    	cin >> ind;
    	char ch;
    	cin >> ch;
    	s[ind - 1] = ch;
    	st.set(ind - 1);

    	cout << st.get() << "\n";

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