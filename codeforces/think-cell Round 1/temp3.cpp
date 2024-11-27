#include <bits/stdc++.h>
#include <debug.h>
using namespace std;


int countBracketSequence(string s){
	int n = s.size();
	int count = 0;
	int f1 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			count += 1;
		else 
			count -= 1;

		if(count < 0)
			f1 = 1;

		if(count < -1)
			return 0;
	}

	if(count > 1)
		return 0;

	if(f1 && count >= 0)
		return 0;

	if(count == 0)
		return 0;

	if(count > 0){
		int ind = 0;
		int temp = 0;
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == ')')
				temp += 1;
			else 
				temp -= 1;

			if(temp < 0){
				ind = i;
				break;
			}
		}
		return n - ind;
	} else {
		int ind = 0;
		int temp = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '(')
				temp += 1;
			else 
				temp -= 1;

			if(temp < 0){
				ind = i;
				break;
			}
		}
		return ind + 1;
	}
}

int main(){
	string inp;
	cin >> inp;
	int ans = countBracketSequence(inp);
	cout << ans << "\n";
}