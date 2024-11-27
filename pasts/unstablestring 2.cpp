
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
    int start = 0;

    int n = s.size();
    ll count = n;

    int ques = 0;


	int f = 1;
	for(int i = 0; i < n; i++){
		if(s[i] != '?')f = 0;
	}

	if(f){
		count += (1ll * n * (n - 1)) / 2;
		cout << count << "\n";
		return;
	}
	int ind = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != '?'){
			ind = i; break;}
		else{
			ques++;
		}
	}
	count += (1ll * ques * (ques - 1)) / 2;

    for(int i = ind; i < n; i++){

    	int look = s[i] - '0';
    	int countq = 0;
    	int j = i;

    	while(j < n && (s[j] == '?' || s[j] - '0' == look)){

    		if(s[j] == '?'){
    			countq++;
    		}
    		else{
    			countq = 0;
    		}
    		j++;
    		look = (look + 1) % 2;
    	}
    	int len = (j - i);

    	count += (1ll * len * (len - 1)) / 2 + (1ll * ques * len);

    	ques = countq;
    	i = j - 1;
    }	
    cout << count << "\n";
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
},