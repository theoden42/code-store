#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    string s;
    cin >> s;
    vector<int> suff(n + 1);
    multiset<int> rind;
    for(int i = n - 1; i >= 0; i--){
    	suff[i] = suff[i + 1];
    	suff[i] += (s[i] == 'R');
    	if(s[i] == 'R'){
    		rind.insert(i);
    	}
    }

    vector<int> ind;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'L' && suff[i] > ind.size()){
    		ind.push_back(i);
    	}
    }
    vector<int> prefix(n + 1);
    for(int i = 1; i <= n; i++){
    	prefix[i] += prefix[i - 1];
    	prefix[i] += a[i - 1];
    }
    int ans = 0;	
    while(!ind.empty()){
    	auto it = ind.back();
    	ind.pop_back();
    	auto rit = --rind.end();
    	int lindex = it;
    	int rindex = *rit;
    	rind.erase(rit);
    	int sum = prefix[rindex + 1] - prefix[lindex];
    	ans += sum;
    }
    cout << ans << "\n";
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