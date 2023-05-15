#include<bits/stdc++.h>

using namespace std;

void solve_divyansh(){
	long long n, m, bs, limit;
	cin >> n >> m >> bs >> limit;
	long long gp[n+1][n+1];
	for(int i = 0; i<m; i++){
		long long x, y;
		cin >> x >> y;
		gp[x][y] = 1;
	}
	long long moves = 0;
	for(int j=0; j<2*limit +1; j++){
		string s = "";
		cin >> s;
		if(s == "AC"){
			//cout << moves;
			break;
		}
		else if(s == "F")
			break;
		else{
			long long x;
			cin >> x;
			long long deg[x], flag[x];qqqqqqq
			for(int i = 0; i<x; i++){
				cin >> deg[i] >> flag[i];
			}
			long long max = 0;
			long long index = 0;
			for(int i = 0; i<x; i++){
       			max = 0;
				if(flag[i] == 0){
					if(deg[i] > max){
						index = i + 1;
						max = deg[i];
					}
        		}
			}
      		if(index == 0){
       			cout << index + 1<<"\n";
      		}
      		else{
				cout << index <<"\n";
				}
      		}
		}

}

int main(){
	int tc;
	cin >> tc;
	while(tc--> 0){
		solve_divyansh();
	}
}
