// Consistency is the key.
// Even if you have started late you can still achieve many things.
// Always upsolve the problem after the contest.
// Don't give up without even trying the problem.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(),a.end()
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define nd second
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<pi>
#define v2i vector<vi>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vi, greater<int> >
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl 
#define pb push_back
#define endl "\n"
const int mod = (int )1e9 + 7;

void test_cases(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    stack<char> st;
    
    for0(i, n) {
        if(st.empty()) st.push(str[i]);
        else {
            if(str[i] == st.top()) st.pop();
            else st.push(str[i]);
        }
    }
    if(st.size() <= 1) cy;
    else cn;
}

signed main(){
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif


    ll t = 1;
    cin >> t;
    while(t--){
        test_cases();
    }
    return 0;
}