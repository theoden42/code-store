
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

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    if(n < 3){
    	for(auto &x : ele){
    		cout << x << " ";
    	}
    	cout << "\n";
    	return;
    }

    sort(all(ele));
	vector<int> temp1;
	vector<int> temp2;


	auto check = [&](vector<int>& x){
		int n = x.size();
		for(int i = 0; i < n - 2; i++){
			if(x[i] <= x[i + 1] && x[i + 1] <= x[i + 2])return false;
			if(x[i] >= x[i + 1] && x[i + 1] >= x[i + 2])return false;
		}
		return true;
	};

	if(n % 2 == 0){
		for(int i = 0; i < n / 2; i++){
			temp1.push_back(ele[i]);
			temp1.push_back(ele[n - i - 1]);
			temp2.push_back(ele[n - i - 1]);
			temp2.push_back(ele[i]);
		}
	}
	else{
		for(int i = 0; i < n / 2 ; i++){
			temp1.push_back(ele[i]);
			temp1.push_back(ele[n - i - 1]);
			temp2.push_back(ele[n - i - 1]);
			temp2.push_back(ele[i]);
		}

		temp1.push_back(ele[n / 2]);
		temp2.push_back(ele[n / 2]);

	}

	debug(temp1, temp2);

	if(check(temp1)){
		for(auto& x: temp1){
			cout << x << " ";
		}
		cout << "\n";
	}
	else if(check(temp2)){
		for(auto& x: temp2){
			cout << x << " ";
		}
		cout << "\n";

	}
	else{
		cout << "-1\n";
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