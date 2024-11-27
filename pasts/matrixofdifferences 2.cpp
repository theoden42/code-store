
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
    set<int> st;
    int n;
    cin >> n;
    int val = n * n;
    for(int i = 1; i <= val; i++){
    	st.insert(i);
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++){
    	if(i % 2 == 0){
    		for(int j = 0; j < n; j++){
    			if(j % 2 == 0){
    				matrix[i][j] = *(st.begin());
    				st.erase(st.begin());
    			}	
    			else{
    				matrix[i][j] = *(--st.end());
    				st.erase(--st.end());
    			}
    		}
    	}
    	else{
    		for(int j = n - 1; j >= 0; j--){
    			if(j % 2 != 0){
    				matrix[i][j] = *(st.begin());
    				st.erase(st.begin());
    			}	
    			else{
    				matrix[i][j] = *(--st.end());
    				st.erase(--st.end());
    			}
    		}
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cout << matrix[i][j] << " ";
    	}
    	cout << "\n";
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