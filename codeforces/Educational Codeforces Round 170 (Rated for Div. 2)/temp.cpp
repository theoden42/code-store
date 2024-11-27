#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> transactions;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		if(x <= 0 || y == 0){
			cout << "Invalid Transaction" << endl;
			return 0;
		}
		transactions.emplace_back(x, y);
	}
	int aval_units = 0;
	int price_inves = 0;
	queue<pair<int,int>> stocks_aval;
	for(auto [prc_txn, num_txn]: transactions){
		if(num_txn >= 0){
			stocks_aval.push({prc_txn, num_txn});
			aval_units += num_txn;
			price_inves += prc_txn * num_txn;
		} else {
			int rem = -num_txn;
			// sell order of 10 
			// queue -> {10, 3}, {20, 6}, {30, 5}
			// 10 -> removed, rem = 7
			// 20 -> removed, rem = 1
			while(!stocks_aval.empty() 
					&& stocks_aval.front().second < rem){
				auto [price, num] = stocks_aval.front();
				stocks_aval.pop();
				aval_units -= num;
				price_inves -= (price * num);
				rem -= num;
			}
			// rem > 0 but no stocks are available.
			if(rem > 0 && stocks_aval.empty()){
				cout 
				<< "Error! Not enough stocks to sell" << endl;
				return 0;
			}
			// 30, {30, 5 - 1} = {30, 4} -> remaining in our inven
			stocks_aval.front().second -= rem;
			aval_units -= rem;
			price_inves -= 
				(stocks_aval.front().first) * rem;
		}
		if(aval_units == 0){
			cout << 0 << endl;
			continue;
		}
		double avg = (double)(price_inves) / aval_units;
		cout << avg << endl;
	}

	return 0;
}



