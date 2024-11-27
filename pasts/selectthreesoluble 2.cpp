
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

void solve() 
{
	int n;
	cin>>n;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int it1=1,it2=3,ans=INT_MAX;
	while(it2<=n)
	{
		ans=min(ans,abs(v[it2]-v[it1+1])+abs(v[it1]-v[it1+1]));
		it1++;it2++;
	}
	cout<<ans<<"\n";

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