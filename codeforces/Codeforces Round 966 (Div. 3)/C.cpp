
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]].push_back(i);
    }
    cin >> m;
    vector<string> s(m);
    for(int i = 0; i < m; i++){
    	cin >> s[i];
    }
    if(mp.size() > 26){
    	for(int i = 0; i < m; i++){
    		cout << "NO\n";
    	}
    	return;
    }
    for(auto& temp: s){
    	if(temp.size() != a.size()){
    		cout << "NO\n";
    		continue;
    	}
    	map<char,int> cor;
    	int ind = 0;
    	int f = 0;
    	for(auto ch: temp){
    		if(cor.find(ch) == cor.end()){
    			cor[ch] = a[ind];
    		} else if(cor[ch] != a[ind]) {
    			f = 1;
    		}
    		ind += 1;
    	}
    	map<int,char> cor2;
    	for(int i = 0; i < n; i++){
    		if(cor2.find(a[i]) == cor2.end()){
    			cor2[a[i]] = temp[i];
    		} else if(cor2[a[i]] != temp[i]){
    			f = 1;
    		}
    	}
    	if(!f){
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
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