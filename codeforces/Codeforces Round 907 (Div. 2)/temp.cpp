#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
deque<int> q;

vector<string> split(string s){
	vector<string> ans;
	string temp = "";
	for(auto c: s){
		if(c == ' '){
			ans.push_back(temp);
			temp = "";
		} else{
			temp += c;
		}
	}
	ans.push_back(temp);
	return ans;
}

void solve(const string& user_input){
	vector<string> s = split(user_input);
	if(s[0] == "PUSH"){
		int value = stoi(s[1]);
		q.push_back(value);
	} else if(s[0] == "EJECT"){
		if(!q.empty())
			q.pop_front();
	} else if(s[0] == "INJECT"){
		int value = stoi(s[1]);
		q.push_front(value);
	} else if(s[0] == "POP"){
		if(!q.empty()){
			ans.push_back(q.back());
			q.pop_back();
		} else {
			ans.push_back(-1);
		}
	} else {
		for(auto v: ans){
			if(v == -1){
				cout << "Empty ";
			} else {
				cout << v << " ";
			}
		}
		cout << "\n";
	}
}

int main(){
	solve("PUSH 5");
	solve("POP");
	solve("SHOW");
}