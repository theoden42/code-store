i
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

struct node { 
	vector<int> zeros, ones;
	int sz;
	node() { 
		zeros.resize(3, 0); ones.resize(3, 0);
		sz = 1;
	}
	node(int v) { 
		zeros.resize(3, !v); ones.resize(3, v);
		sz = 1;
	}
};

template<class T, class U>
struct Lsegtree{
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;

    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }


    T combine(T l, T r)
    {

    	T ans = 0;
    	ans.sz = l.sz + r.sz;
    	ans.zeros[0] = (l.zeros[0] == l.sz) ? l.zeros[0] + r.zeros[0] : l.zeros[0];
    	ans.zeros[1] = (r.zeros[1] == r.sz) ? r.zeros[1] + l.zeros[1] : r.zeros[1];
    	ans.zeros[2] = max({l.zeros[2], r.zeros[2], l.zeros[1] + r.zeros[0]});	

    	ans.ones[0] = (l.ones[0] == l.sz) ? l.ones[0] + r.ones[0] : l.ones[0];
    	ans.ones[1] = (r.ones[1] == r.sz) ? r.ones[1] + l.ones[1] : r.ones[1];
    	ans.ones[2] = max({l.ones[2], r.ones[2], l.ones[1] + r.ones[0]});	
        return ans;
    }


    void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
    {
        if(tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }



    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
    	if(upd & 1) {
    		swap(curr.zeros, curr.ones);
    	}
    	return curr;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
    	U ans_upd = (old_upd + new_upd) % 2;
    	return ans_upd;
    }  


    void push_down(ll v, ll tl, ll tr)
    {
        //for the below line to work, make sure the "==" operator is defined for U.
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 2 < 4*n)
        {
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r)
        {
            return identity_element;
        }
        if(l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        if(tl >=l and tr <=r)
        {
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else
        {
            ll tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }

    void build(vector<T>a)
    {
        assert( (ll)a.size() == n);
        buildUtil(0,0,n-1,a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0,0,n-1,l,r);
    }
    void update(ll l,ll r, U upd)
    {
        updateUtil(0,0,n-1,l,r,upd);
    }
};



void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
    	v[i] = s[i] - '0';
    }

	Lsegtree<node, int> lsg(n, node(0), 0);
	vector<node> nv(n);
	for(int i = 0; i < n; ++i){ 
		nv[i] = node(v[i]);
	}
	lsg.build(nv);


	for(int i = 0; i < q; i++){
		int c, l, r;
		cin >> c >> l >> r;
		l--;
		r--;
		if(c == 1) { 
			lsg.update(l, r, 1);
		} else { 
			node temp = lsg.query(l, r);
			cout << temp.ones[2] << "\n";
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