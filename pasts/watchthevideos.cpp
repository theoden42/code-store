
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> videos(n);
    for(int i = 0; i < n; i++){
    	cin >> videos[i];
    }
    sort(videos.begin(), videos.end());
    int time  = 0;
    time = accumulate(all(videos), 0ll);

    int i = 0; int j = n - 1;
    int space = m;
    multiset<int> downs;
    debug(time);

    while(i <= j){
    	// i will donwload the largest video possible
    	if(space >= videos[j]){
    		space -= videos[j];
    		// while downloading I would watch the videos that I can watch
    		int watch = 0;
    		while(!downs.empty() && watch < videos[j]){
    			auto it = --downs.end();
    			space += *it;
    			downs.erase(it);
    			watch++;
    		}
    		downs.insert(videos[j]);
    		j--;
    	}
    	else if(space >= videos[i]){
    		// can i donwload the smallest video possible ? 
    		space -= videos[i];
    		int watch = 0;
    		while(!downs.empty() && watch < videos[i]){
    			auto it = --downs.end();
    			space += *it;
    			downs.erase(it);
    			watch++;
    		}
    		downs.insert(videos[i]);
    		i++;
    	}
    	else{
    		while(space < videos[i]){
    			auto it = --downs.end();
    			space += *it;
    			downs.erase(it);
    			time++;
    		}
    	}
    } 
    time++;
    cout << time << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}