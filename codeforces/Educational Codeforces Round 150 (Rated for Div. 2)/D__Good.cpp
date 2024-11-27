#include<bits/stdc++.h>
// #ifdef ONLINE_JUDGE
// #define debug(x...)
// #else
// #include "../debug.hpp"
// #endif
#define ll long long
#define in(A,N); int A[N]; for(int z=0;z<N;z++){cin>>A[z];}
#define pt(A,N); for(int z=0;z<N;z++){cout<<A[z]<<" ";} cout<<endl;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int ll
using namespace std;

signed main()
{	fio;
	int t = 1;
	cin >> t;
	while (t--)
	{	int N;
		cin >> N;
		vector<pair<int, int>>v;
		for (int i = 0; i < N; i++)
		{
			int l, r;
			cin >> l >> r;
			v.push_back({r, l});
		}
		sort(v.begin(), v.end());
		// debug(v);
		vector<int>dp(N+1,0);
		dp[0]=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<i-1;j++)
			{
				// debug(i,j);
				if(v[i-1].second>v[j].first)
					continue;
				int mi=min(v[i-1].second,v[j].second);
				pair<int,int>p={mi,0};
				int ind=upper_bound(v.begin(),v.end(),p)-v.begin();
				if(ind>j)
					continue;
				dp[i]=max(dp[i],dp[ind]+1);
			}
			dp[i]=max(dp[i],dp[i-1]);
		}
		cout<<N-2*dp[N]<<endl;
	}


	return 0;
}


