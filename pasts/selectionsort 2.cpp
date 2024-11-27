#include <bits/stdc++.h>
using namespace std;

int main(){

	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i<N; i++){
		cin >> arr[i];
	}
	int min = 1e9;
	int index = -1;
	for(int i = 0; i<N-1; i++){
		min = 1e9;
		index = -1;
		for(int j = i; j<N; j++){
			if(min >= arr[j]){
				min = arr[j];
				index = j;
			}
		}
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
		for(int j = 0; j<N; j++){
			cout << arr[j] << " ";

		}
		cout << "\n";
	}
	return 0;
}