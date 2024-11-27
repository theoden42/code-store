#include <bits/stdc++.h>
#include <debug.h>
using namespace std;


vector<int> solution(vector<string> queries, int diff){
	int sum = 0;
	map<int,int> mp;
	map<int,int> count;
	vector<int> ans;

	for(auto s: queries){
		string temp = s.substr(1, s.size() - 1);
		int val = stoi(temp);

		if(s[0] == '+'){
			mp[val] += 1;
			sum -= count[val];
			sum -= count[val - diff];
			sum -= count[val - 2 * diff];

			count[val] = mp[val] * mp[val + diff] * mp[val + 2 * diff];
			count[val - diff] = mp[val - diff] * mp[val] * mp[val + diff];
			count[val - 2 * diff] = mp[val - 2 * diff] * mp[val - diff] * mp[val];

			sum += count[val];
			sum += count[val - diff];
			sum += count[val - 2 * diff];
		} else {
			mp[val] = 0;

			sum -= count[val];
			sum -= count[val - diff];
			sum -= count[val - 2 * diff];
			count[val] = 0;
			count[val - diff] = 0;
			count[val - 2 * diff] = 0;
		}
		debug(count);
		debug(val, count[val]);
		ans.push_back(sum);
	}

	return ans;
}

int main(){
	vector<string> q = {"+2", "+3", "+9", "+4", "+0", "-2", "+6", "+1", "-3", "+12", "+7", "+3", "+3"};
	vector<int> ans = solution(q, 3);
	debug(ans);
}