

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
	int root;
	vector<int> indices;
	vector<node*> children;
};

void dfs(node* root, vector<int> &ind){
    if(root == NULL)
        return;

     for(auto x: root->indices){
         ind.push_back(x);
     }
     for(auto child: root->children){
         dfs(child, ind);
     }

}

void solve() {
    int q;
    cin >> q;
    vector<node*> mp(5e5 + 5, NULL);

    int index = 0;

    for(int i = 1; i <= q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int x;
    		cin >> x;
    		if(mp[x] == NULL){
    			node* nd = new node();
    			nd->root = x;
    			nd->indices.push_back(index++);
    			mp[x] = nd;
    		}
    		else{
    			mp[x]->indices.push_back(index++);
    		}
    	}else{
    		int x, y;
    		cin >> x >> y;
            if(x == y)
                continue;

    		if(mp[x] == NULL)
    			continue;

            if(mp[y] == NULL){
                node *ny = new node();
                ny->root = y;
                mp[y] = ny;
            }

    		mp[y]->children.push_back(mp[x]);
    		mp[x] = NULL;
    	}
    }

    vector<int> ans(index);

    for(int i = 0; i <= 5e5; i++){
        if(mp[i] == NULL)
            continue;

    	vector<int> values;

    	dfs(mp[i], values);
    	int val = mp[i]->root;

    	for(auto x: values){
    		ans[x] = val;
    	}
    }

    for(auto x: ans){
    	cout << x << " ";
    }
    cout << "\n";

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