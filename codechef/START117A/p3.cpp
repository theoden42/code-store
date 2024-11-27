#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

long long solution(vector<int> a){
	unordered_map<string,int> mp;	
	int n = a.size();
	long long count = 0;
	for(int i = 0; i < n; i++){
		string x = to_string(a[i]);
		long long tempc = 0;
		unordered_set<string> st;
		for(int j = 0; j < x.size(); j++){
			string bck = x.substr(j, x.size() - j);
			string fnt = x.substr(0, j);
			string v = bck;
			v += fnt;
			st.insert(v);
		}
		for(auto s: st){
			tempc += mp[s];
		}
		count += tempc;
		mp[x] += 1;
	}

	return count;

}

int main(){
	int x = solution({42, 402, 402, 240}); 
	debug(x);
}