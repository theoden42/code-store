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

const int MAX_N = 100;
const int maxh = 100;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<vector<int>> lookup(MAX_N, vector<int> (MAX_N));  

void buildSparseTable(vector<int> arr, int n)
{
    // Initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
 
    // Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {
 
        // Compute maximum value for all intervals with
        // size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
 
            // For arr[2][10], we compare arr[lookup[0][7]]
            // and arr[lookup[3][10]]
            if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range
    // For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute maximum of last 2^j elements with first
    // 2^j elements in range
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]]
    if (lookup[L][j] >= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
 
    else
        return lookup[R - (1 << j) + 1][j];
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int,int>> height(maxh, {0, -1});
    vector<pair<int, int>> height2(maxh, {0, -1});
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    buildSparseTable(arr, n);
    for(int i = 0; i < n; i++){
    	if(height[arr[i]].second == -1){
    		height[arr[i]].first = 0;
    		height[arr[i]].second = i;
    	}
    	else if(query(height[arr[i]].second, i) == arr[i]){
    		height[arr[i]].first = height[arr[i]].first + 1;
    		height[arr[i]].second = i;
    	}
    	else{
    		height[arr[i]].first = 0;
    		height[arr[i]].second = i;
    	}
    }
    for(int i = n - 1; i >= 0; i--){
    	if(height2[arr[i]].second == -1){
    		height2[arr[i]].first = 0;
    		height2[arr[i]].second = i;
    	}
    	else if(query(height2[arr[i]].second, i) == arr[i]){
    		height2[arr[i]].first = height[arr[i]].first + 1;
    		height2[arr[i]].second = i;
    	}
    	else{
    		height2[arr[i]].first = 0;
    		height2[arr[i]].second = i;
    	}
    }
    for(int i = 0; i < n; i++){
    	cout << height[arr[i]].first + height2[arr[i]].first << " ";
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