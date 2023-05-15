#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0; i<n; i++){
		cin >> ar[i];
	}
	int sum[n];
	int startindex[n];
	sum[0] =  ar[0];
	startindex[0] = 0;
	for(int i = 1; i<n; i++){
		if(sum[i-1] + ar[i] > ar[i]){
			sum[i] = ar[i] + sum[i-1];
			startindex[i] = startindex[i-1];
		}
		else{
		 	sum[i] = ar[i];
		 	startindex[i] = i;

		}
	}
	int max = sum[0];
	int ind = 0;
	for(int i = 0; i<n; i++){
		if(max < sum[i]){
			max = sum[i];
			ind = i;
		}
	}
	cout << "The maximum sum is  " << max << " for range " << startindex[ind] << " to " << ind << "\n";
}