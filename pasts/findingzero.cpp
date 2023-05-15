#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n; 
    cin >> n;
    if(n % 2 == 0){
    	vector<bool> iszero(n+1, true);
    	iszero[0] = false;
    	for(int i = 1; i <= (n - 2)/2; i++){
    		vector<int> test(4);
    		vector<pair<int, int>> result;
    		int k = 0;
    		for(int j = 1; j <= n && k < 4; j++){
    			if(iszero[j]){
    				test[k++] = j;
    			}
    		}
    		int z = 0;
    		cout << "? " << test[1] << ' ' << test[2] << ' ' << test[3] << endl;
    		cin >> z;
    		result.emplace_back(z, test[0]);
    		cout << "? " << test[0] << ' ' << test[2] <<' ' << test[3] << endl;
    		cin >> z;
    		result.emplace_back(z, test[1]);
    		cout << "? " << test[0] << ' ' << test[1] <<' ' << test[3] <<endl;
    		cin >> z;
    		result.emplace_back(z, test[2]);
    		cout << "? " << test[0] << ' ' << test[1] << ' ' << test[2] << endl;
    		cin >> z;
    		result.emplace_back(z, test[3]);


    		sort(all(result));
    		auto it = result.end();
    		it--;
    		iszero[it->second] = false;
    		it--;
     		iszero[it->second] = false;
   		 }
    	cout << "! ";
    	for(int i = 1; i <= n;  i++){
    		if(iszero[i]){
    			cout << i << " ";
    		}
    	}
    	cout << endl;
	}
	else{
		vector<bool> iszero(n+1, true);
    	iszero[0] = false;
    	for(int i = 1; i <= (n - 3)/2; i++){
    		vector<int> test(4);
    		vector<pair<int, int>> result;
    		int k = 0;
    		for(int j = 1; j <= n && k < 4; j++){
    			if(iszero[j]){
    				test[k++] = j;
    			}
    		}
    		int z = 0;
    		cout << "? " << test[1] << ' ' << test[2] << ' ' << test[3] << endl;
    		cin >> z;
    		result.emplace_back(z, test[0]);
    		cout << "? " << test[0] << ' ' << test[2] <<' ' << test[3] << endl;
    		cin >> z;
    		result.emplace_back(z, test[1]);
    		cout << "? " << test[0] << ' ' << test[1] <<' ' << test[3] <<endl;
    		cin >> z;
    		result.emplace_back(z, test[2]);
    		cout << "? " << test[0] << ' ' << test[1] << ' ' << test[2] << endl;
    		cin >> z;
    		result.emplace_back(z, test[3]);

    		sort(all(result));
    		auto it = result.end();
    		it--;
    		iszero[it->second] = false;
    		it--;
     		iszero[it->second] = false;
   		 }
   		vector<int> test(4);
    	vector<pair<int, int>> result;
    	int k = 0;
    	for(int j = 1; j <= n; j++){
    		if(!iszero[j]){
    			test[k] = j;
    			break;
    		}
    	}
    	for(int j = 1, k = 1; j <= n-1 && k < 3; j++){
    		if(iszero[j]){
    			test[k++] = j;
    		}
    	}
    	test[3] = n;

    	int z = 0;
    	cout << "? " << test[1] << ' ' << test[2] << ' ' << test[3] << endl;
    	cin >> z;
    	result.emplace_back(z, test[0]);
    	cout << "? " << test[0] << ' ' << test[2] <<' ' << test[3] << endl;
    	cin >> z;
    	result.emplace_back(z, test[1]);
    	cout << "? " << test[0] << ' ' << test[1] <<' ' << test[3] <<endl;
    	cin >> z;
    	result.emplace_back(z, test[2]);
    	cout << "? " << test[0] << ' ' << test[1] << ' ' << test[2] << endl;
    	cin >> z;
    	result.emplace_back(z, test[3]);


    	sort(all(result));
    	auto it = result.end();
    	it--;
    	iszero[it->second] = false;
    	it--;
     	iszero[it->second] = false;

    	cout << "! ";
    	for(int i = 1; i <= n;  i++){
    		if(iszero[i]){
    			cout << i << " ";
    		}
    	}
    	cout << endl;
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