#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
#ifdef AMAN_MAC
#include "debug.h"
#else
#define debug(...)
#endif

using namespace __gnu_pbds;using namespace std;
#define int int64_t

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
template <typename T> std::istream& operator>>(std::istream& in, std::vector<T>& vec) { for(auto &v : vec) in>>v;return in;}
template <typename T> std::ostream& operator<<(std::ostream& out,std::vector<T>& vec) { for(auto &v : vec) out<<v<<" ";return out;}
int mul(int a, int b) { return ((a % M) * (b % M)) % M; }int madd(int a, int b) { return (a % M + b % M) % M; }
int mpow(int a, int b) { int pow = a, res = 1; while (b) { if (b & 1)res = mul(res, pow);pow = mul(pow, pow);b >>= 1; }return res; }
int minv(int a) { return mpow(a, M - 2); }int mdiv(int a, int b) { return mul(a, minv(b)); }int msub(int a, int b) { return (a % M - b % M + M) % M; }
int binlog(int a,int b){ int cnt=0; while(a>=b){a/=b; cnt++; } return cnt; }
void solve() {
	string s;cin>>s;
	int m=s.length();
	string b="";
	vector<int> arr(26);
	for(int i=m-1;i>=0;i--){
		if(arr[s[i]-'a']==0)b+=s[i];
		arr[s[i]-'a']++;
	}
	reverse(b.begin(),b.end());
	arr.assign(26,0);int x=b.length();
	string a="";
	for(int i=0;i<m;i++){
		int x=b.length();
		int v=(i+1)*(x+1);
		arr[s[i]-'a']++;
		for(auto&ele:b)v-=arr[ele-'a']*x--;
		if(v==m){
			a=s.substr(0,i+1);
			break;
		}
	}
	if(a=="")cout<<-1;
	else {
		string res="";
		string tem=a;
		for(int i=0;i<b.length();i++){
			res+=a;
			string c="";
			for(auto &ele:a){
				if(ele==b[i])continue;
				c+=ele;
			}
			a=c;
		}
		if(res==s)cout<<tem<<" "<<b;
		else cout<<-1;
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin >> t; for(int i = 0;i < t; i++ ) { solve(); cout << "\n";}
    return 0;
}