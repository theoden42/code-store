#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;

	cin >> s;

	if((s[0] == 'a' || s[0] == 'h') && (s[1] == '1' || s[1] == '8')){
		cout << 3 << "\n";
	}
	else if(s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8'){
		cout << 5 << '\n';
	}
	else{
		cout << 8 << "\n";
	}
}