
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '*')count++;
    }

    if(count % 2 == 0){
    	int index = -1;
    	vector<int> left;
    	vector<int> right;	
    	int x = 0;

    	for(int i = 0; i < n; i++){
    		if(s[i] == '*')x++;
    		if(x == count / 2){
    			index = i;
    			break;
    		}
    	}
    	debug(index);

    	for(int i = 0; i < index; i++){
    		if(s[i] == '*')left.push_back(i);
    	}
    	for(int i = index + 1; i < n; i++){
    		if(s[i] == '*')right.push_back(i);
    	}

    	debug(left, right);

    	ll count = 0;
    	for(int i = left.size() - 1; i >= 0; i--){
    		count += index + (i -  left.size()) - left[i];
    	}
    	for(int i = 0; i < right.size(); i++){
    		count += right[i] - index  - 1 - i;
    	}
    	cout << count << "\n";
    }
    else{
    	int index = -1;
    	vector<int> left;
    	vector<int> right;	
    	int x = 0;

    	for(int i = 0; i < n; i++){
    		if(s[i] == '*')x++;
    		if(x == count / 2 + 1){
    			index = i;
    			break;
    		}
    	}
    	debug(index);

    	for(int i = 0; i < index; i++){
    		if(s[i] == '*')left.push_back(i);
    	}
    	for(int i = index + 1; i < n; i++){
    		if(s[i] == '*')right.push_back(i);
    	}
    	ll count = 0;

    	debug(left, right);

    	for(int i = left.size() - 1; i >= 0; i--){
    		count += index + (i -  left.size()) - left[i];
    	}


    	for(int i = 0; i < right.size(); i++){
    		count += right[i] - index - 1 - i;
    	}
    	cout << count << "\n";
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