
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
    int q;

    cin >> q;
    vector<vector<int>> prefix(n, vector<int>(26, 0));
    prefix[0][s[0] - 'a']++;

    for(int i = 1; i < n; i++){
    	for(int j = 0; j < 26; j++){
    		prefix[i][j] = prefix[i - 1][j];
    	}
    	prefix[i][s[i] - 'a']++;
    }

    int count = 0;

    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	l--;
    	r--;
    	if(l == r){
    		count++;
    		continue;
    	}
    	if(l == r - 1){
    		continue;
    	}

    	vector<int> left(26, 0);
    	vector<int> right(26, 0);
    	int mid = (l + r) / 2;

    	for(int j = 0; j < 26; j++){
    		left[j] = prefix[mid][j] - prefix[l][j];
    		right[j] = prefix[r][j] - prefix[mid + 1][j];
    	}

    	left[s[l] - 'a']++;
    	right[s[mid + 1] - 'a']++;


    	if((r - l) % 2 == 0){
    		int flag = 0;
    		for(int j = 0; j < 26; j++){
    			if(left[j] == right[j])
    				continue;
    			else if(abs(left[j] - right[j]) == 1)
    				flag++;
    			else
    				flag = 2;
    		}
    		if(flag == 1){
    			count++;
    		}
    		else{
    			int mid = (l + r) / 2 - 1;
    			for(int j = 0; j < 26; j++){
    				left[j] = prefix[mid][j] - prefix[l][j];
    				right[j] = prefix[r][j] - prefix[mid + 1][j];
    			}
    			left[s[l] - 'a']++;
    			right[s[mid + 1] - 'a']++;
    			int flag = 0;
    			for(int j = 0; j < 26; j++){
    				if(left[j] == right[j]){
    					continue;
    				}
    				else if(abs(left[j] - right[j]) == 1){
    					flag ++;
    				}
    				else{
    					flag = 2;
    				}
    			}
    			if(flag == 1){
    				count++;
    			}
    		}
    	}
    	else{
    		continue;
    	}
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
         cout << "Case #" << t << ": ";
        solve();
    }
}