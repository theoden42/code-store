

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

struct Trie { 
	struct node { 
		node *left, *right;
		node():left(nullptr),right(nullptr){}
	};
	node* root;
	Trie(){
		root = new node();
	}
	void insert(int val){
		node* temp = root;
		for(int i = 30; i >= 0; i--){
			if(val >> i & 1){
				if(temp->right){
					temp = temp->right;
				} else {
					node* nwnode = new node();
					temp->right = nwnode;	
					temp = temp->right;
				} 
			} else {
				if(!temp->left){
					temp->left = new node();
				}
				temp = temp->left;
			}
		}
	}

	int maxval(int val){
		node* temp = root;
		int xr = 0;
		for(int i = 30; i >= 0; i--){
			if(val >> i & 1){
				if(temp->left){
					xr += (1 << i);
					temp = temp->left;
				} else {
					temp = temp->right;
				}
			} else {
				if(temp->right){
					xr += (1 << i);
					temp = temp->right;
				} else {
					temp = temp->left;
				}
			}
		}
		return xr;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n - 1);
	for(int i = 0; i < n - 1; i++){
		cin >> a[i];
	}
	vector<int> pref(n);
	for(int i = 1; i < n; i++){
		pref[i] = pref[i - 1] ^ a[i - 1];
	}

	Trie t;
	for(int i = 1; i < n; i++){
		t.insert(pref[i]);
	}
	int b = 0;
	for(int i = 0; i < n; i++){
		int mx = t.maxval(i);
		if(mx <= n - 1){
			b = i;
			break;
		}
	}

	vector<int> bans(n);
	bans[0] = b;
	for(int i = 1; i < n; i++){
		bans[i] = a[i - 1] ^ bans[i - 1];
	}

	for(int i = 0; i < n; i++){
		cout << bans[i] << " ";
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