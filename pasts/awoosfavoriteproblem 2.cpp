
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
		int n;
        string s,t;
    	cin>>n>>s>>t;
    	int sa=0,sc=0,ta=0,tc=0;
    	string s1="",s2="";
       	for(int i=0;i<n;i++)
    	{
    		if(s[i] == 'a')	
    			sa++;
    		else if(s[i] == 'c')	
    			sc++;
     
    		if(t[i] == 'a')	
    			ta++;
    		else if(t[i] == 'c')	
    			tc++;
    		
    		if(s[i] != 'b')	
    			s1 += s[i];
    		if(t[i] != 'b')	
    			s2 += t[i];
       		if(sc>tc||sa<ta){
    			cout<< "NO" <<endl;
                return;
            }
    }
    if(s1==s2){
    cout<< "YES" <<endl;
    return;}
    cout<<"NO" <<endl;
    
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