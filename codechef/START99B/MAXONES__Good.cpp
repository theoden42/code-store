#include<bits/stdc++.h>
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
		string S;
		cin >> S;
		N = S.length();
		auto allone = [&]()
		{
			for (auto it : S)
			{
				if (it == '0')
					return false;

			}
			return true;
		};
		auto allzero = [&]()
		{
			for (auto it : S)
			{
				if (it == '1')
					return false;

			}
			return true;
		};
		auto xr = [](char a, char b)
		{
			int A = a - '0';
			int B = b - '0';
			int C = A ^ B;
			char c = C + '0';
			return c;
		};
		auto isunchangable = [&]()
		{
			for (int i = 1; i < N-1; i++)
			{
				// debug(S[i],xr(S[i - 1], S[i + 1]));
				if (xr(S[i - 1], S[i + 1]) != S[i])
					return false;
				// debug(S[i],xr(S[i - 1], S[i + 1]));
			}
			return true;
		};
		if (allone())
		{	cout << S << endl;
			continue;
		}
		if (allzero())
		{
			cout << S << endl;
			continue;
		}
		if (isunchangable())
		{
			cout << S << endl;
			continue;
		}
		if (S == "001")
			S = "011";
		if (S == "100")
			S = "110";
		if (N <= 3)
		{
			cout << S << endl;
			continue;
		}
		if (N == 5 && S == "11011")
		{
			cout << S << endl;
			continue;
		}
		if (N == 4 && S == "1101")
		{
			cout << S << endl;
			continue;
		}
		if (S[0] == '1' && S[N - 1] == '1')
		{

			S[1] = '0';
			for (int i = 2; i < N; i++)
			{
				S[i] = '1';
			}
			cout << S << endl;
			continue;
		}
		if (S[0] == '1')
		{
			for (int i = 1; i < N - 1; i++)
			{
				S[i] = '1';
			}
			cout << S << endl;
			continue;
		}
		if (S[N - 1] == '1')
		{
			for (int i = 1; i < N; i++)
			{
				S[i] = '1';
			}
			cout << S << endl;
			continue;
		}
		for (int i = 1; i < N - 1; i++)
		{
			S[i] = '1';

		}
		cout << S << endl;
	}

	return 0;
}


/*
getting better
closer
edge cases
*/