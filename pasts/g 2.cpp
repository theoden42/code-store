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


void build_tree(long long* b, vector<ll>& seg_tree,
                int l, int r, int vertex)
{
    // Termination Condition
    if (l == r) {
        seg_tree[vertex] = b[l];
        return;
    }
 
    // Find the mid value
    int mid = (l + r) / 2;
 
    // Left and Right  Recursive Call
    build_tree(b, seg_tree, l, mid,
               2 * vertex);
    build_tree(b, seg_tree, mid + 1,
               r, 2 * vertex + 1);
 
    // Update the Segment Tree Node
    seg_tree[vertex] = __gcd(seg_tree[2 * vertex],
                             seg_tree[2 * vertex + 1]);
}

int range_gcd(vector<ll>& seg_tree, int v,
              int tl, int tr,
              int l, int r)
{
    // Base Case
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return seg_tree[v];
 
    // Find the middle range
    int tm = (tl + tr) / 2;
 
    // Find the GCD and return
    return __gcd(
        range_gcd(seg_tree, 2 * v, tl,
                  tm, l, min(tm, r)),
 
        range_gcd(seg_tree, 2 * v + 1,
                  tm + 1, tr,
                  max(tm + 1, l), r));
}

int maxSubarrayLen(ll arr[], int n)
{
    // Stores the Segment Tree
    vector<ll> seg_tree(4 * (n) + 1, 0);
 
    // Function call to build the
    // Segment tree from array arr[]
    build_tree(arr, seg_tree, 0, n - 1, 1);
 
    // Store maximum length of subarray
    int maxLen = 0;
 
    // Starting and ending pointer of
    // the current window
    int l = 0, r = 0;
      while (r < n && l < n) {
 
        // Case where the GCD of the
        // current window is 1
        if (range_gcd(seg_tree, 1, 0,
                      n - 1, l, r)
            == 1) {
            l++;
        }
 
        // Update the maximum length
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
 
    // Print answer
 	return maxLen;
}


void solve() {
    int n;
    cin >> n;
    vector<ll> ele(n, 0);

    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    if(n == 1){
    	cout << 1 << "\n";
    	return;
    }
    if(n == 2){
    	if(abs(ele[1] - ele[0]) == 1){
    		cout << 1 << "\n";
    		return;
    	}
    	cout << 2 << "\n";
    	return;
    }

    ll arr[n - 1];
    for(int i = 1; i < n; i++){
    	arr[i - 1] = abs(ele[i] - ele[i - 1]);
    }

    int ans = maxSubarrayLen(arr, n - 1) + 1;
    cout << ans << "\n";
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