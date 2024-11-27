int stockSpike(vector<int> prices, int k){
	int n = prices.size();
	vector<int> left(n), right(n);
	multiset<int> mst;

	for(int i = 0; i < n; i++){
		if(mst.size() == k && *mst.rbegin() < prices[i])
			left[i] = 1;
		if(mst.size() < k)
			mst.insert(prices[i]);
		else if(*mst.rbegin() > prices[i]){
			mst.erase(mst.rbegin());
			mst.insert(prices[i]);
		}
	}

	mst.clear();
	for(int i = n - 1; i >= 0; i--){
		if(mst.size() == k && *mst.rbegin() < prices[i])
			right[i] = 1;

		if(mst.size() < k)
			mst.insert(a[i]);
		else if(*mst.rbegin() > prices[i]){
			mst.erase(mst.rbegin());
			mst.insert(a[i]);
		}
	}

	int count = 0;
	for(int i = 0; i < n; i++){
		if(left[i] && right[i])
			count++;
	}
	return count;
}
