#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n; 
    cin >> n;
    vector<int> choice(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> choice[i];
    }
    vector<int> ans(n, -1);
    vector<int> notfilled;
    int count = 0;
    map<int, int> assn;
    for(int i = 0; i < n; i ++){
    	if(assn.find(choice[i]) == assn.end()){
    		count++;
    		assn[choice[i]] = i;
    		ans[i] = choice[i];
    	}
    	else{
    		notfilled.push_back(i);
    		continue;
    	}
    }
    for(int i = 1; i <= n; i++){
    	if(assn.find(i) == assn.end()){
    		if(notfilled.back() + 1 == i){
    			if(notfilled.size() == 1){
    				int temp = assn[choice[notfilled.back()]];
    				ans[temp] = i;
    				ans[notfilled.back()] = choice[notfilled.back()];
    				assn[choice[notfilled.back()]] = notfilled.back();
    				assn[i] =  temp;
    			}
    			else{
    				ans[notfilled[0]] = i;
    				notfilled.erase(notfilled.begin());
    				assn[i] = 0; 
    			}
    		}
    		else{
    			ans[notfilled.back()] = i;
    			assn[i] = notfilled.back();
    			notfilled.pop_back();
    		}
    	}
    }
    cout << count << "\n";
    for(auto& x : ans){
    	cout << x << " ";
    }
    cout << "\n";
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