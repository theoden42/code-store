#include <bits/stdc++.h>
#include <debug.h>
using namespace std;


int solution(vector<int> times){
	sort(times.begin(), times.end());
	queue<int> q;
	int n = times.size();
	int last = 0;
	int mx = 0;
	for(int i = 0; i < n; i++){
		while(!q.empty() && q.front() <= times[i]){
			last = max(last, q.front());
			q.pop();
		}
		if(q.size() >= 12){
			continue;
		} else {
			int pushtime = max(mx, times[i]);
			int outtime = pushtime + 300;
			q.push(outtime);
			mx = max(mx, outtime);
		}
	}
	while(!q.empty()){
		last = max(last, q.front());
		q.pop();
	}

	return last;
}

int main(){
	int ans = solution({21, 30, 33, 45, 46, 49, 51, 53, 55, 56, 63, 65, 70, 73, 75});
	cout << ans << "\n";
}

