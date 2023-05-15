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

int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}

//gfg lis in nlogn
int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
 
        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];
 
        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
 
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
 
    return length;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	mp[ele[i]]++;
    }
    // sort(ele.begin(), ele.end());
    // vector<int> ans(n, 0);
    // int k = 0;
    // for(int i = 0; i < n / 2.0; i++){
    // 	ans[i] = ele[k];
    // 	k += 2;
    // }
    // if(n % 2 == 0){
    // 	k = n - 1;
    // }
    // else{
    // 	k = n - 2;
    // }
    // for(int i = ceil(n / 2.0);i < n;  i++){
    // 	ans[i] = ele[k];
    // 	k -= 2;
    // }
    // int count1 = LongestIncreasingSubsequenceLength(ans);
    // reverse(ans.begin(), ans.end());
    // int count2 = LongestIncreasingSubsequenceLength(ans);
    // cout << min(count1, count2) << "\n";
    int val = n;
    for(auto& x: mp){
    	if(x.second > 2){
    		val -= (x.second - 2);
    	}
    	if(x.second == n){
    		cout << 1 << "\n";
    		return;
    	}
    }
    cout << (val + 1) / 2 << "\n";

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