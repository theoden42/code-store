
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> guest(n);
    vector<int> tab(m);
    vector<int> freq(n + 1, 0);


    for(int i = 0; i < n; i++){
    	cin >> guest[i];
    }

    for(int i = 0; i < n; i++){
    	freq[guest[i]]++;
    }

    for(int i = 0; i < m; i++){
    	cin >> tab[i];
    }

    priority_queue<int, greater<int>> pq;

    for(int i = 0; i < n; i++){
    	pq.push(freq[i]);
    }

    int count = 0;

    for(int i = 0; i < m; i++){
    	int val = *(--mst.end());
    	mst.erase(--mst.end());
    	int temp = min(tables[i], val);
    	val -= temp;
    	count += temp;
    	mst.insert(val);
    }
    cout << count << "\n";	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int testcases = 1;
    cin >> testcases;
    for (int t = 1; t <= testcases; t++) {
        solve();
    }
}