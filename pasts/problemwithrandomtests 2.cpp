
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

void comparemx(vector<int>& t, vector<int>& mx){
	int sz = mx.size();
	int flag = 0;
	for(int i = 0; i < sz; i++){
		if(t[i] > mx[i]){
			flag = 1;
			break;
		}
		else if(mx[i] > t[i]){
			break;
		}
	}
	if(flag){
		for(int i = 0; i < sz; i++){
			mx[i] = t[i];
		}
	}
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		ele[i] = s[i] - '0';
	}

	int ind = -1;
	for(int i = 0; i < n; i++){
		if(ele[i] == 1){
			ind = i;
			break;
		}
	}
	if(ind == -1){
		cout << 0 << "\n";
		return;
	}

	int ind2 = -1;
	for(int i = ind + 1; i < n; i++){
		if(ele[i] == 0){
			ind2 = i;
			break;
		}
	}
	if(ind2 == -1){
		for(int i = ind; i < n; i++){
			cout << ele[i] << " ";
		}
		cout << "\n";
		return;
	}



	int j = ind;
	vector<int> mx = ele;
	vector<int> temp(n - ind2, 0);

	debug(temp, ind, ind2);

	while(j < ind2){
		// starting from this index j take in n - ind2 characters and put it in temp
		int count = 0;
		for(int i = 0; i < n - ind2; i++){
			temp[i] = 0;
		}
		for(int i = j; i < j + n - ind2; i++){
			temp[count++] = ele[i];
		}
		debug(temp);
		// I have this temp set and I have the mx set, now I need to find this xor 
		vector<int> xr(n, 0);
		for(int i = 0; i < n; i++){
			if(i < ind2){
				xr[i] = ele[i];
			}
			else{
				xr[i] = (ele[i] |  temp[i - ind2]);
			}
		}
		debug(xr, mx);
		comparemx(xr, mx);
		j++;
	}
	for(int i = ind; i < n; i++){
		cout << mx[i];
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