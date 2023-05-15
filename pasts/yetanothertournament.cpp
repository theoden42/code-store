
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.first < p2.first)return true;
	if(p1.first > p2.first)return false;

	if(p1.second > p2.second)return true;
	else return false;

}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; ++i){
    	vp[i] = {ele[i], i};
    }
    sort(all(vp), cmp);
    int count = 0;
    int temp = m;


    int lastindex = -1;
    for(int i = 0; i < n; i++){
    	if(temp >= vp[i].first){
    		count++;
    		lastindex = vp[i].second;
    		temp -= vp[i].first;
    	}
    	else{
    		break;
    	}
    }


    if(count == n){
    	cout << 1 << "\n";
    }
    else if(count == 0){
    	cout << n + 1 << "\n";
    }
    else{
    	int val = ele[count]; // with same number of wins; can i fit this or not? 
    	int lastinsert = ele[lastindex];

    	debug(val, lastinsert, temp);

    	if(val < lastinsert || temp + lastinsert >= val){
    		cout << n - count << "\n";
    	}
    	else{
    		cout << n - count + 1 << "\n";
    	}
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}