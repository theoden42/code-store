#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> price(n, 0);
	vector<string> vit(n, "");

	int aflag = 0, bflag = 0, cflag = 0;

	for(int i = 0; i<n; i++){
		int t;
		string x;
		cin >> t >> x;
		price[i] = t;
		vit[i] = x;
		if(vit[i].find("A") != string::npos){
			aflag = 1;
		}
		if(vit[i].find("B") != string::npos){
			bflag = 1;
		}
		if(vit[i].find("C") != string::npos){
			cflag = 1;
		}
	}

	if(!(aflag && bflag && cflag)){
		cout << "-1" << "\n";
		return 0;
	}

	int minprice = 1e9;

	for(int i = 0; i<n; i++){
		int p = 1e9;
		string x = vit[i];
		if((x.find("A") == string::npos)){
			continue;
		}
		else{
			p = price[i];
			if(x.find("B") != string::npos && x.find("C") != string::npos){
				p = price[i];
			}
			else if(x.find("B") != string::npos){
				int min= 1e9;
				for(int j = 0; j<n; j++){
					if(vit[j].find("C") != string::npos){
						if(price[j] < min){
							min = price[j];
						}
					}
				}
				p += min;
			}
			else if(x.find("C") != string::npos){
				int min= 1e9;
				for(int j = 0; j<n; j++){
					if(vit[j].find("B") != string::npos){
						if(price[j] < min){
							min = price[j];
						}
					}
				}
				p += min;
			}
			else{
				int min = 1e9;
				for(int j =  0; j<n; j++){
					int p2 = 10e7; 
					string y = vit[j];
					if(y.find("B") != string::npos && y.find("C") != string::npos){
						p2 = price[j];
					}
					else if(y.find("B") != string::npos){
						p2 = price[j];
						int min3 = 1e9;
						for(int k = 0; k<n; k++){
							if(vit[k].find("C") != string::npos){
								if(price[k] < min3){
									min3 = price[k];
								}
							}
						}
						p2 += min3;
					}
					else if(y.find("C") != string::npos){
						p2 = price[j];
						int min3 = 1e9;
						for(int k = 0; k<n; k++){
							if(vit[k].find("B") != string::npos){
								if(price[k] < min3){
									min3 = price[k];
								}
							}
						}
						p2 += min3;
					}
					if(p2 < min){
						min = p2;
					}
				}
				p += min;
			}
			if(p<minprice){
				minprice = p;
			}
		}
	}
	cout << minprice << "\n";

}
