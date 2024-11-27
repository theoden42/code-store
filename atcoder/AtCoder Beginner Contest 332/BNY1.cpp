

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

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAX_N = 1e6 + 5;

template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden = 0ll;
   
	T combine(T a, T b){
 	    T temp;	
 	    temp = a + b;
 		return temp ;
 	}
 	T single_value(int v){
    	T temp;
    	temp = v;
 		return temp;
 	}
    
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		arr.resize(2 * sz, iden);
	}

	void build(vector<int>& a){
		build(a, 0, 0, sz);
	}

	void set(int ind, int value){
		setUtil(ind, value, 0, 0, sz);
	}

	T get(int l, int r){
		return getUtil(l, r, 0, 0, sz);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				arr[x] = single_value(a[lx]);
			}	
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}

	T getUtil(int l, int r, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
        T left = getUtil(l, r, 2 * x + 1, lx, m);
		T right = getUtil(l, r, 2 * x + 2, m, rx);
		return combine(left, right);
	}

	void setUtil(int ind, int val, int x, int lx, int rx){
		if(rx - lx == 1){
			arr[x] = single_value(val);
			return;
		}

		int m = (lx + rx) / 2;
		if(ind < m){
			setUtil(ind, val, 2 * x + 1, lx, m);
		}
		else{
			setUtil(ind, val, 2 * x + 2, m, rx);
		}

		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}
};

vector<bool> is_prime(MAX_N + 1, true);;
vector<int> spf(MAX_N + 1);

void sieve(){
	is_prime[0] = is_prime[1] = false;
    spf[0] = 0;
    spf[1] = 1;
    
    for(int i = 2; i <= MAX_N; i++){
        spf[i] = i;
    }

    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i){
                is_prime[j] = false;
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<long long> Divisor_Queries(int N, int Q, vector<int> a,
					 vector<vector<int>> Queries){
	sieve();
	SegTree<long long> st;
	st.init(N);
	st.build(a);

	set<int> nonones;
	for(int i = 1; i <= N; i++){
		if(a[i - 1] != 1){
			nonones.insert(i);
		}
	}

	vector<long long> result;

	for(auto q: Queries){
		if(q[0] == 1){
			int l = q[1];
			int r = q[2];
			auto it = nonones.lower_bound(l);
			while(!nonones.empty() && it != nonones.end() && *it <= r){
				int index = *it;
				int p = spf[a[index - 1]];
				a[index - 1] /= p;

				cout << index << " " << a[index - 1] << "\n";
				st.set(index - 1, a[index - 1]);
				if(a[index - 1] == 1){
					nonones.erase(index);
				}
				it = nonones.upper_bound(index);
			}
		} else if(q[0] == 2) {
			int l = q[1];
			int r = q[2];
			auto sum = st.get(l - 1, r);
			result.push_back(sum);

		} else {
			int i = q[1];
			int k = q[2];
			st.set(i - 1, k);
			a[i - 1] = k;
			if(a[i - 1] != 1){
				nonones.insert(i);
			}
		}
	}
	return result;
}


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    vector<vector<int>> query;
    for(int i = 0; i < q; i++){
    	int x, y, z;
    	cin >> x >> y >> z;
    	query.push_back({x, y, z});
    }
    vector<long long> ans = Divisor_Queries(n, q, a, query);
    for(auto a: ans){
    	cout << a << "\n";
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