

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

template<typename T, typename U>
struct LSegTree {
    int sz = 1;
    vector<T> arr;
    vector<U> updates;
    T iden = 0; // define the identity element here
    U iden_upd = -1; // define the identity update here
   
    T combine(T a, T b){
        // define how to combine two nodes
        T temp = a + b; 
        return temp;
    }

    T single_value(int v){
        // what to store in leaves corresponding to array value v
        T temp = v;
        return temp;
    }

    T apply_update(T node, U update, int tl, int tr) { 
        if(update == -1)
            return node;
        node = (tr - tl) * update;
        return node;
    }

    U combine_update(U old_upd, U new_upd, int tl, int tr) { 
        // define how to combine update into one, with endpoints tl and tr
        return new_upd;
    }

    void init(int n){
        while(sz < n){
            sz *= 2;
        }
        arr.resize(2 * sz, iden);
        updates.resize(2 * sz, iden_upd);
    }

    void propogate(int x, int lx, int rx) { 
        if(updates[x] == iden_upd) { 
            return;
        }
        arr[x] = apply_update(arr[x], updates[x], lx, rx);
        if(2 * x + 2 < 2 * sz) { 
            int m = (lx + rx) / 2;
            updates[2 * x + 1] = combine_update(updates[2 * x + 1], updates[x], lx, m);
            updates[2 * x + 2] = combine_update(updates[2 * x + 2], updates[x], m, rx);
        }
        updates[x] = iden_upd;
    }

    void build(vector<int>& a){
        build(a, 0, 0, sz);
    }

    void update(int l, int r, U upd){
        updateUtil(l, r, upd, 0, 0, sz);
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

    T getIndex(int l, int r, int x){
        int lb = l;
        int ub = r - 1;
        int ans = ub;
        while(lb <= ub){
            int mid = lb + (ub - lb) / 2;
            if(get(mid, mid + 1) >= x){
                ans = mid;
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
        return ans;
    }


    T getUtil(int l, int r, int x, int lx, int rx){
        propogate(x, lx, rx);
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

    void updateUtil(int l, int r, U upd, int x, int lx, int rx){
        propogate(x, lx, rx);
        if(lx >= r || l >= rx)
            return;

        if(lx >= l && rx <= r) {
            updates[x] = combine_update(updates[x], upd, lx, rx);
            propogate(x, lx, rx);
            return;
        }
        
        int m = (lx + rx) / 2;
        updateUtil(l, r, upd, 2 * x + 1, lx, m);
        updateUtil(l, r, upd, 2 * x + 2, m, rx);
        arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
    }
};

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<int> ans(n, 1e9);
    int left = 0;
    int right = 0;
    map<int,int> freq; multiset<int> mst;

    for(int l = 0; l <= n - k; l++){
    	int lind = l;
    	int rind = l + k;
    	while(right < rind){
    		if(freq[a[right] - right] > 0)
    			mst.erase(mst.find(freq[a[right] - right]));
    		freq[a[right] - right] += 1;
    		mst.insert(freq[a[right] - right]);
    		right += 1;
    	}
    	while(left < lind){
    		mst.erase(mst.find(freq[a[left] - left]));
    		freq[a[left] - left] -= 1;
    		if(freq[a[left] - left] > 0){
    			mst.insert(freq[a[left] - left]);
    		}
    		left += 1;
    	}
    	int mx = k - *prev(mst.end(), 1);
    	ans[l] = mx;
    }

    vector<vector<int>> qu(q);
    vector<int> q_ans(q);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        qu[i] = {l, r, i};
    }
    sort(all(qu));
    reverse(all(qu));

    LSegTree<int,int> lst;
    vector<int> c(n, 1e9);
    c[n - 1] = ans[n - k];
    // debug(c);
    lst.init(n);
    lst.build(c);
    int curr_x = n - k;
    for(int i = 0; i < q; i++){
        int l = qu[i][0];
        int r = qu[i][1];
        for(int j = curr_x; j > l; j--){
            int ind =  lst.getIndex(j + k - 2, n, ans[j - 1]);
            lst.update(j + k - 2, ind + 1, ans[j - 1]);
        }
        int query_val = lst.get(l + k - 1, r + 1);
        q_ans[qu[i][2]] = query_val;
        curr_x = l;
    }

    for(auto x: q_ans){
        cout << x << "\n";
    }
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