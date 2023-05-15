
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


void inmap(int& x, map<int,int>& mp, int *size){
	if(mp.find(x) == mp.end() || mp[x] == 0){
		mp[x] = 1;
		(*size)++;
	}
	else{
		mp[x]++;
	}
}


void outmap(int& x, map<int,int>& mp, int* size){
	if(mp.find(x) == mp.end() || mp[x] == 0){
		return;
	}
	if(mp[x] == 1){
		(*size)--;
		mp[x] = 0;
	}
	else{
		mp[x]--;
	}
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    if(k == 0){
    	cout << 0 << "\n";
    	return;
    }

    map<int,int> mp;
    int size = 0;
    ll count = 0;
    int j = 0;

    for(int i = 0; i < n; i++){
    	debug(i, j, mp, size);
    	while(!((mp.find(ele[j]) == mp.end() || mp[ele[j]] == 0) && size == k) && j < n){
    		inmap(ele[j], mp, &size);
    		j++;
    	}
   		count += j - i;
    	outmap(ele[i], mp, &size);
    }

    cout << count << "\n";	
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