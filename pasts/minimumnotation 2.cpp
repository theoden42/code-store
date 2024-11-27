
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
    string s;
    cin >> s;
    int n = s.size();
    multiset<int> setstring;
    multiset<int> newstring;
    multiset<int> newstring2;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	ele[i] = s[i] - '0';
    	setstring.insert(ele[i]);
    }

    string final = "";
    for(int i = 0; i < n; i++){
    	if(ele[i] == *(setstring.begin())){
    		newstring2.insert(*setstring.begin());
    		setstring.erase(setstring.begin());
    	}
    	else{
    		setstring.erase(setstring.find(ele[i]));
    		newstring.insert(min(ele[i] + 1, 9));
    	}
    }

    while(!newstring.empty() && !newstring2.empty()){
		if(*newstring.begin() < *newstring2.begin()){
			final += (char)(*newstring.begin() + '0');
			newstring.erase(newstring.begin());
		}
		else{
			final += (char)(*newstring2.begin() + '0');
			newstring2.erase(newstring2.begin());
		}
    }
    while(!newstring.empty()){
    	final += (char)(*newstring.begin() + '0');
    	newstring.erase(newstring.begin());
    }
    while(!newstring2.empty()){
    	final += (char)(*newstring2.begin() + '0');
    	newstring2.erase(newstring2.begin());
    }

    cout << final << "\n";
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