

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

int check(int height, int width, multiset<pair<int,int>>& ord_height, multiset<pair<int,int>>& ord_width){

	debug(ord_height, ord_width, height, width);

	if(ord_height.empty() && (height == 0 || width == 0))return true;
	else if(ord_height.empty())return false;

	int w = (--ord_width.end())->first;

	if(w > width)return false;
	else if(w == width){

		while(!ord_width.empty()){
			auto it = (--ord_width.end());
			if(it->first != w)break;

			height -= it->second;
			auto it2 = *it;
			swap(it2.first, it2.second);
			ord_width.erase(it);
			ord_height.erase(ord_height.find(it2));
		}

		if(height < 0)return false;
		else{
			return check(height, width, ord_height, ord_width);
		}
	}
	else{
		auto it = (--ord_height.end());
		if(it->first != height)return false;
		width -= it->second;	
		auto it2 = *it;
		swap(it2.first, it2.second);
		ord_height.erase(it);
		ord_width.erase(ord_width.find(it2));

		return check(height, width, ord_height, ord_width);

	}

}


pair<int,int> get(int n, vector<pair<int,int>>& vp){

	int width = max_element(all(vp))->first;
	int height = 0;
	int ind = -1;
	int mx = 0;

	vector<pair<int,int>> newvp;
	for(int i = 0; i < n; i++){
		if(vp[i].first == width){
			height += vp[i].second;
		}
		else{
			newvp.push_back(vp[i]);
			if(mx < vp[i].second){
				ind = i;
				mx = vp[i].second;
			}
		}
	}
	if(newvp.empty())return {height, width};

	height += mx;
	int f = 1;
	vector<pair<int,int>> temp;
	for(auto x: newvp){
		if(x == vp[ind] && f){
			f = 0;
			continue;
		}
		temp.push_back(x);
	}
	newvp = temp;
	temp.clear();

	multiset<pair<int,int>> ord_width, ord_height;

	for(auto x: newvp){
		ord_width.insert(x);
		ord_height.insert({x.second, x.first});
	}

	if(check(vp[ind].second, width - vp[ind].first, ord_height, ord_width))
		return {height, width};
	else 
		return {-1, -1};
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	cin >> vp[i].second;
    	cin >> vp[i].first;
   	}

   	pair<int,int> ans1 = get(n, vp);
   	for(int i = 0; i < n; i++){
   		swap(vp[i].first, vp[i].second);
   	}

   	pair<int,int> ans2 = get(n, vp);
   	swap(ans2.first, ans2.second);

   	vector<int> x, y;
   	if(ans1.first != -1){
   		x.push_back(ans1.first);
   		y.push_back(ans1.second);
   	}
   	if(ans2.first != -1 && !(ans1 == ans2)){
   		x.push_back(ans2.first);
   		y.push_back(ans2.second);
   	}

   	cout << x.size() << "\n";
   	for(int i = 0; i < x.size(); i++){
   		cout << x[i] << " " << y[i] << "\n";
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