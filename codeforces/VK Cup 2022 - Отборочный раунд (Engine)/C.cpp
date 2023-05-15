

	/* author: (g)theoden42 */

	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>

	using namespace std;
	using namespace __gnu_pbds;

	#define all(a) a.begin(), a.end()
	#ifdef ON_PC
	    #include <debug.h>
	#else
	    #define debug(x...)
	#endif

	template<typename T>
	using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	using ll =  long long;
	using ld = long double;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	const int MAX_N = 1e6 + 5;
	const ll MOD = 1e9 + 7;
	const ll INF = 1e9;

	void solve() {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> mp(26, 0);
		for(int i = 0; i < n; i++){
			mp[s[i] - 'a']++;
		}

		auto getval = [&](int val){
			int times = n / val;
			int count1 = 0;
			int count2 = 0;
			int x = 0;
			for(int i = 0; i < 26; i++){
				if(mp[i] > val){
					count1 += mp[i] - val;
					x++;
				}
			}

			multiset<int> mst;
			for(int i = 0; i < 26; i++){
				if(mp[i] == val)x++;

				if(mp[i] < val)
					mst.insert(mp[i]);
			}
			while(x < times){
				auto it = --mst.end();
				count2 += val - *it;
				mst.erase(it);
				x++;
			}

			return max(count1, count2);
		};

		int mn = n;	
		int ans = 1;

		for(int i = 1; i * i <= n; i++){
			if(n % i != 0)continue;
			int t = n / i;
			if(t <= 26){
				int x = getval(i);
				if(x < mn){
					mn = x;
					ans = i;
				}
			}
			t = i;
			if(t <= 26){
				int x = getval(n / i);
				if(x < mn){
					mn = x;
					ans = n / i;
				}
			}
		}
		cout << mn << "\n";

		string fn = "";
		vector<int> freq(26, 0);

		int x = 0;
		for(int i = 0; i < 26; i++){
			if(mp[i] >= ans)x++;
		}

		multiset<pair<int,int>> mst;
		for(int i = 0; i < 26; i++){
			if(mp[i] < ans){
				mst.insert({mp[i], i});
			}	
		}

		int t = n / ans;
		multiset<int> chars;
		while(x < t){
			auto it = --mst.end();
			chars.insert(it->second);
			x++;
			mst.erase(it);
		}


		for(int i = 0; i < n; i++){
			int ch = s[i] - 'a';
			if(chars.find(ch) != chars.end()){
				freq[ch]++;
			}
		}

		multiset<int> notupdate = chars;

		for(int i = 0; i < n; i++){
			int ch = s[i] - 'a';
			if(mp[ch] == ans || notupdate.find(ch) != notupdate.end()){
				fn += s[i];
			}
			else if(mp[ch] > ans && freq[ch] < ans){
				fn += s[i];
				freq[ch]++;
			}
			else if(mp[ch] > ans && freq[ch] >= ans){
				int x = *(--chars.end());
				fn += (char)('a' + x);
				freq[x]++;
				if(freq[x] == ans){
					chars.erase(--chars.end());
				}
			} 
			else{
				if(chars.find(ch) != chars.end()){
					fn += (char)('a' + ch);
					freq[ch]++;
					if(freq[ch] == ans){
						chars.erase(chars.find(ch));
					}
				}
				else{
					ch = *(--chars.end());
					fn += (char)('a' + ch);
					freq[ch]++;
					if(freq[ch] == ans){
						chars.erase(chars.find(ch));
					}
				}
			}
		}

		cout << fn << "\n";
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