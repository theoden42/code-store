
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    sort(all(ele));
    map<int,int> mp;


    for(int i = 0; i < n; i++){
    	int temp = ele[i];
    	for(int j = 1; j * j <= temp; j++){
    		if(temp % j != 0)continue;

    		mp[j]++;	
    		if(j != temp / j){
    			mp[temp / j]++;
    		}
    	}
    }
    for(int i = 1; i <= m; i++){
    	if(mp[i] == 0){
    		cout << "-1\n";
    		return;
    	}
    }


    int j = 0;
    set<int> st;
    map<int, int> facs;
    for(int i = 1; i <= m; ++i){
    	facs[i] = 0;
    }

    int mx = ele[n - 1] - ele[0];

    for(int i = 0; i < n; i++){

    	while(j < n && st.size() < m){
    		int t = ele[j];

    		for(int k = 1; k * k <= t; k++){
    			if(t % k != 0)continue;

    			if(facs[k] == 0 && k <= m){
    				st.insert(k);
    			}
    			if(k != t / k && facs[t / k] == 0 && t / k <= m){
    				st.insert(t / k);
    			}

    			facs[k]++;
    			if(k != t / k)facs[t / k]++;
    		}
    		j++;
    	}
    	if(st.size() != m)break;



    	mx = min(mx, ele[j - 1] - ele[i]);


		int t = ele[i];
		for(int k = 1; k * k <= t; k++){
			if(t % k != 0)continue;

			facs[k]--;
			if(facs[k] == 0 && k <= m)st.erase(st.find(k));

			if(k != t / k){
				facs[t / k]--;
				if(facs[t / k] == 0 && t / k <= m)st.erase(st.find(t / k));
			}
		}
    }
    cout << mx << "\n";
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