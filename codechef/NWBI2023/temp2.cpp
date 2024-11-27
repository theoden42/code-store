#include<bits/stdc++.h>
using namespace std;

#define Y cout << "YES\n"
#define N cout << "NO\n"
#define endl cout << "\n"
#define rep(i, s, e) for(int i = s; i < e; i++)
#define repd(i, s, e) for(int i = s; i>e; i--)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define ll long long


string bin(int a)
{
    string s;
    for (int i = 0; i < 21; i++)
    {
        /* code */
        if (a % 2 == 0)
        {
            s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
        a = a / 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int bintoint(string r)
{
    reverse(r.begin(), r.end());
    int d = 0;
    for (int j = 0; j < 21; j++)
    {
        string ss = "";
        ss.push_back(r[j]);
        d = d + (stoi(ss)) * pow(2, j);
        // cout << stoi(ss) << " ";
        // cout << (int) (atoi(&r[j]) * pow(2, j))  << " ";
    }
    // cout << "\n";
    return d;
}

ll binexp(ll a,ll b, ll m){
    ll ans=1;
    while(b){
        if(b%2)
        {
            ans=(ans*a)%m;   
        } 
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}

int n, x, y;


map<vector<int>, int> dp;
bool solve(vi &v, int i, int pd, pair<int,int> p)
{

    if(i == n && p.first == x && p.second == y){
        return true;
    }
    else if(i == n || p.first < 0 || p.second < 0 || p.first > 1e4 || p.second > 1e4){
        return false;
    }

    vector<int> curr_state = {i, pd, p.first, p.second};
    if(dp.find(curr_state) != dp.end()){
        return dp[curr_state];
    }

    if(pd == 0){
        dp[curr_state] = (solve(v, i + 1, (pd + 1) % 2, {p.first + v[i], p.second}) || solve(v, i + 1, (pd + 1) % 2, {p.first - v[i], p.second})); 
    }
    else{
        dp[curr_state] = (solve(v, i + 1, (pd + 1) % 2, {p.first, p.second + v[i]}) || solve(v, i + 1, (pd + 1) % 2, {p.first, p.second - v[i]}));
    }

    return dp[curr_state];
}


int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
        cin >> n >> x >> y;
        vi v;
        rep(j,0,n)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        bool f=(solve(v, 0, 1 , {0, 0}) || solve(v, 0, 0, {0, 0}));
        if (f)
        {
            Y;
        }
        else
        {
            N;
        }
    // }
}