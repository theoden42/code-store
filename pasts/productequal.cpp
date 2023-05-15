#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n; 
	cin >> n;
	long long ar[n];
	long long count1 = 0;
	long long count2 = 0;
	long long count0 = 0;
	long long psum = 0; 
	long long nsum = 0;
	for(long long i = 0; i<n; i++){
		cin >> ar[i];
		if(ar[i] > 0){
			count1 ++;
			psum += ar[i];
		}
		else if(ar[i] == 0){
			count0 ++;
		}
		else{
			count2 ++; 
			nsum += ar[i];
		}
	}
	if(count2 % 2 == 0){
		cout << ((psum - count1) + (-count2 - nsum) + count0) << '\n';
	}
	else if(count2 % 2 != 0 && count0 > 0){
		cout << ((psum - count1) + (-count2 - nsum) + count0)<< "\n";
	}
	else{
		cout << (((psum - count1) + (-count2 - nsum + 2) + count0))<< "\n";
	}

}