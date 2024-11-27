

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

#define int long long

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int flag = 0;
int cnt = 0;

int nod(int num){
	int count = 0;
	while(num != 0){
		count++;
		num /= 10;
	}
	return count;
}

vector<int> getvalues(int l){
	vector<int> temp;
	while(l != 0){
		int r = l % 10;
		temp.push_back(r);
		l = l / 10;
	}
	reverse(all(temp));
	return temp;
}


void solve() {
	int l, r;
	cin >> l >> r;


	int n1 = nod(l);
	int n2 = nod(r);

	if(n1 != n2){
		int x = min(n1, n2);
		for(int i = 1; i <= x; i++){
			cout << "9";
		}
		cout << "\n";
		return;
	}

	vector<int> a, b;
	a = getvalues(l);
	b = getvalues(r);


	multiset<int> st;
	string ans = "";

	int i = 0;
	while(i < n1 && a[i] == b[i]){
		ans += (char)('0' + a[i]);
		st.insert(a[i]);
		i++;
	}

	if(i == n1){
		cout << ans << "\n";
		return ;
	}


	// debug(ans);

	int x = a[i];
	int y = b[i];

	int flag1 = 1;
	int flag2 = 1;
	int ind1 = -1;
	int ind2 = -1;

	int mn = 11;
	int d = -1;


	for(int k = x + 1; k < y; k++){

		st.insert(k);
		int t3 = *(--st.end()) - *(st.begin());
		st.erase(st.find(k));

		if(t3 < mn){
			mn = t3;
			d = k;
		}
	}

	for(int j = i; j < n1; j++){
		if(a[j] > x ){
			ind1 = j;
			flag1 = 0;
			break;
		}
		else if(a[j] < x){
			break;
		}
	}


	for(int j = i; j < n1; j++){
		if(y > b[j]){
			ind2 = j;
			flag2 = 0;
			break;
		}
		else if(b[j] > y){
			break;
		}
	}


	if(flag1 && flag2){
		st.insert(x);
		int t1 = *(--st.end()) - *(st.begin());
		st.erase(st.find(x));

		st.insert(y);
		int t2  = *(--st.end()) - *(st.begin());
		st.erase(st.find(y));

		if(mn < t1 && mn < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + d);
			}
			cout << ans << "\n";
			return;
		}

		if(t1 < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + x);
			}
			cout << ans << "\n";
			return;
		}
		else{
			for(int j = i; j < n1; j++){
				ans += (char)('0' + y);
			}
			cout << ans << "\n";
			return;
		}
	}
	else if(flag1){
		st.insert(x);
		int t1 = *(--st.end()) - *(st.begin());
		st.erase(st.find(x));

		int f = 0;
		int z = y - 1;

		for(int j = i + 1; j < ind2; j++){
			z = y - 1;
			f = 1;
			ind2 = j;
			break;
		}

		if(!f){
			z = b[ind2];
			for(int j = ind2; j < n1; j++){
				if(b[j] < b[ind2] ){
					z = b[ind2] - 1;
					break;
				}
				else if(b[j] > b[ind2]){
					break;
				}
			}
		}


		st.insert(y);
		st.insert(z);
		int t2 = *(--st.end()) - *(st.begin());
		st.erase(st.find(y));
		st.erase(st.find(z));

		if(mn < t1 && mn < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + d);
			}
			cout << ans << "\n";
			return;
		}

		if(t1 < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + x);
			}
			cout << ans << "\n";
		}
		else{
			for(int j = i; j < ind2; j++){
				ans += (char)('0' + y);
			}
			for(int j = ind2; j < n1; j++){
				ans += (char)('0' + z);
			}
			cout << ans << "\n";
		}

	}
	else if(flag2){
		st.insert(y);
		int t1 = *(--st.end()) - *(st.begin());
		st.erase(st.find(y));



		int f = 0;
		int z = x + 1;

		for(int j = i + 1; j < ind1; j++){
			z = x + 1;
			f = 1;
			ind1 = j;
			break;
		}

		if(!f){
			z = a[ind1];
			for(int j = ind1; j < n1; j++){
				if(a[j] > a[ind1] ){
					z = z + 1;
					break;
				}
				else if(a[j] < a[ind1]){
					break;
				}
			}		
		}

		st.insert(x);
		st.insert(z);
		int t2 = *(--st.end()) - *(st.begin());
		st.erase(st.find(x));
		st.erase(st.find(z));


		if(mn < t1 && mn < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + d);
			}
			cout << ans << "\n";
			return;
		}

		if(t1 < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + y);
			}
			cout << ans << "\n";
		}
		else{
			for(int j = i; j < ind1; j++){
				ans += (char)('0' + x);
			}
			for(int j = ind1; j < n1; j++){
				ans += (char)('0' + z);
			}
			cout << ans << "\n";
		}
	}
	else{


		int f = 0;
		int z1 = x + 1;

		for(int j = i + 1; j < ind1; j++){
			z1 = x + 1;
			f = 1;
			ind1 = j;
			break;
		}

		if(!f){
			z1 = a[ind1];
			for(int j = ind1; j < n1; j++){
				if(a[j] > a[ind1] ){
					z1 = z1 + 1;
					break;
				}
				else if(a[j] < a[ind1]){
					break;
				}
			}		
		}


		st.insert(x);
		st.insert(z1);
		int t1 = *(--st.end()) - *(st.begin());
		st.erase(st.find(x));
		st.erase(st.find(z1));



		f = 0;
		int z2 = y - 1;

		for(int j = i + 1; j < ind2; j++){
			z2 = y - 1;
			f = 1;
			ind2 = j;
			break;
		}

		if(!f){
			z2 = b[ind2];
			for(int j = ind2; j < n1; j++){
				if(b[j] < b[ind2] ){
					z2 = b[ind2] - 1;
					break;
				}
				else if(b[j] > b[ind2]){
					break;
				}
			}
		}


		st.insert(y);
		st.insert(z2);
		int t2 = *(--st.end()) - *(st.begin());
		st.erase(st.find(y));
		st.erase(st.find(z2));


		if(mn < t1 && mn < t2){
			for(int j = i; j < n1; j++){
				ans += (char)('0' + d);
			}
			cout << ans << "\n";
			return;
		}

		if(t1 < t2){
			for(int j = i; j < ind1; j++){
				ans += (char)('0' + x);
			}
			for(int j = ind1; j < n1; j++){
				ans += (char)('0' + z1);
			}

			cout << ans << "\n";
		}
		else{
			for(int j = i; j < ind2; j++){
				ans += (char)('0' + y);
			}
			for(int j = ind2; j < n1; j++){
				ans += (char)('0' + z2);
			}
			cout << ans << "\n";
		}
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