
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

struct node{
	int min, times;
	node(int m, int t){
		min = m;
		times = t;
	}
};


struct segTree{
	int size;
	vector<node> arr;

	void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        node nd;
        nd.init()
        arr.assign(2 * size, );
    }
	
};

void solve() {
	int n, m;
    cin >> n >> m;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    segTree st;
    st.init(n);

    st.build(ele);
    debug(st.arr);
    for(int i = 1; i <= m; i++){
    	int q, in, v;
    	cin >> q >> in >> v;
    	if(q == 1){
    		st.set(in, v);
    	}
    	else{
    		cout << st.get(in, v) << "\n";
    	}
    }
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