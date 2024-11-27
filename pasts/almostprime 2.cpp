#include <bits/stdc++.h>
using namespace std;

bool isprime(int a){
	if( a == 1){
		return false;
	}
	for(int i = 2; i * i <= a; i++){
		if(a % i == 0){
			return false;
		} 
	}
	return true;
}
 bool almost(int x){
 	int count = 0; 
 	for(int i = 1; i <= x && x!= 1; i++){
 		if(isprime(i) && x%i == 0){
 			count ++;
 			while(x % i == 0){
 				x /= i;
 			}
 		}
 	}
 	if(count == 2){
 		return true;
 	}
 	return false;
 }

int main(){
	int a; 
	cin >> a;
	int count = 0;
	for(int i = 2; i<=a; i++){
		if(almost(i)){
			count ++;
		}
	}
	cout << count ;

	return 0;
}