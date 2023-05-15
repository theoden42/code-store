
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
const int INF = 1e9 + 5;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}	

	vector<pair<int,int>> ta(n), tb(n);

	for(int i = 0; i < n; i++){
		ta[i] = {a[i], i};
		tb[i] = {b[i], i};
	}
	sort(all(ta));
	sort(all(tb));

	int i = n - 1; 
	int j = n - 1; 

	map<int,int> mpa;
	map<int,int> mpb;

	int mn = INF;

	debug(ta, tb);

	while(i >= 0 && j >= 0){
		debug(i, j);


		int v1 = ta[i].first;
		int v2 = tb[j].first;
		int ind1 = ta[i].second;
		int ind2 = tb[j].second;

		if(ind1 == ind2){
			if(i > 0){
				mn = min({mn, abs(ta[i - 1].first - tb[j].first)});
			}
			if(j > 0){
				mn = min(mn, abs(ta[i].first - tb[j - 1].first));
			}
			if(v1 > v2){
				i--;
				mpb[ind1] = 1;
			}
			else{
				j--;
				mpa[ind1] = 1;
			}
			continue;
		}
		debug(abs(v1 - v2));
		mn = min(mn, abs(v1 - v2));

		if(v1 > v2 && mpa[ind1] != 1){
			i--;
			mpb[ind1] = 1;
		}
		else if(v2 > v1 && mpb[ind2] != 1){
			j--;
			mpa[ind2] = 1;
		}
		else{
			break;
		}
	}
	cout << mn << "\n";

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