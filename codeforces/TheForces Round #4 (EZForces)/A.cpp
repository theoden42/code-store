
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


vector<int> ps;

void preprocess(){
	for(int i = 0; i * i <= 1e9 + 5; i++){
		ps.push_back(i * i);
	}
}

int findlarger(int target){
	int n = ps.size();
	int low = 0;
	int high = n - 1;
	int ind = n;
	while(low <= high){
		int mid = (low + (high - low) / 2);
		if(ps[mid] >= target){
			ind = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ind;
}	


void solve() {
    int l, r;
    cin >> l >> r;
    int ind1 = findlarger(l);
    int ind2 = findlarger(r);

    if((int)sqrt(r) * (int)sqrt(r) == r){
    	cout << ind2 - ind1 + 1 << "\n";
    }
    else{
    	cout << ind2 - ind1 << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

}