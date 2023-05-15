	#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#ifdef YASH_PC
#include <debug.h>
#else
#define debug(x...)
#endif

#define YES cout << "YES" \
                 << "\n"
#define NO cout << "NO" \
                << "\n"
#define endl "\n"
#define pb push_back
#define int long long
const int M = 1e9 + 7;
#define all(a) a.begin(), a.end()
bool f(int n,vector<int>&v,int target,vector<vector<int>>&dp)
{ 
    if(target==0){
        return true;
    }
    if(n==0){
        if(v[0]==target){
            return true;
        }
        else{
            return false;
        }
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
      bool nottake=f(n-1,v,target,dp);
    bool take=false;
      if(target>=v[n])
    take=f(n-1,v,target-v[n],dp);
    return dp[n][target]=(take | nottake);
    }
void solve()
{
    int n;
    cin>> n;
    int t;
    vector<int>v(n);
    int sum=0;
    for(int i = 0;i < n; i++){
        cin >> v[i];
        sum = sum + v[i];
    }

    vector<vector<int>>dp(n + 1, vector<int>(sum + 1, -1));

    t = sum/2;
    if(sum % 2 == 0){
    	if(f(n-1,v,t,dp)){
    		cout << "true\n";
    	}
    	else{
    		cout << "false\n";
    	}
	}
    else{	
        cout << "false" << "\n";
    }
    }
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
     cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}