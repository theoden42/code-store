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
map<vector<int>,bool> dp;
bool solve(vi &v, int i, char pd, pair<int, int> p)
{
    vector<int> curr_state = {i, pd - 'a', p.first, p.second};

    auto itr=dp.find(curr_state);

    if (itr != dp.end())
    {
        return itr->second;
    }

    if (p.first==x && p.second==y && i==(n))
    {
        return dp[curr_state] = true;
    }
    else if(i == n || (p.first < 0) || p.second < 0 || p.first>1e4 || p.second>1e4)
    {
        return dp[curr_state]=false;
    }

    if (pd=='u' ||  pd=='s')
    {
        if(solve(v, i+1, 'l' , make_pair(p.first-v[i], p.second)))
        {
            return dp[curr_state]=true;
        }
    }
    if (pd=='l' ||  pd=='s')
    {
        if(solve(v, i+1, 'u', make_pair(p.first, p.second-v[i])))
        {
            return dp[curr_state]=true;
        }
    }
    return dp[curr_state]=false;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y;
    vi v;
    rep(j,0,n)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    bool f=solve(v,0,'s',{0,0});
    if (f)
    {
        Y;
    }
    else
    {
        N;
    }
}