
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


	vector<string> cl(n);
	vector<int> ds(n, 0);
	vector<int> us(n, 0);

	vector<string> cl2(n);
	vector<int> ds2(n, 0);
	vector<int> us2(n, 0);


	for(int i = 0; i < n; i++){
		string x;
		cin >> cl[i];
		cin >> ds[i];
		cin >> us[i];
		cl2[i] = cl[i];
		ds2[i] = ds[i];
		us2[i] = us[i];
	}	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(cl[i].compare(cl[j]) == 0){
				if(us[i] > us[j]){
					int temp = us[i];
					us[i] = us[j];
					us[j] = temp;
					string t = cl[j];
					cl[j] = cl[i];
					cl[i] = t;
				}
			}
			else if(cl[i].compare(cl[j]) > 0){
					int temp = us[i];
					us[i] = us[j];
					us[j] = temp;
					string t = cl[j];
					cl[j] = cl[i];
					cl[i] = t;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(ds2[i] == ds2[j]){
				if(us2[i] > us2[j]){
					int temp = us2[i];
					us2[i] = us2[j];
					us2[j] = temp;
					int t = ds2[j];
					ds2[j] = ds2[i];
					ds2[i] = t;
				}
			}
			else if(ds2[i] > ds2[j]){
					int temp = us2[i];
					us2[i] = us2[j];
					us2[j] = temp;
					int t = ds2[j];
					ds2[j] = ds2[i];
					ds2[i] = t;

			}
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(us[i] == us2[i])
			count++;
	}
	cout << count << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}