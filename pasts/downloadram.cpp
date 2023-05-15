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

bool check(vector<vector<int>> v, int x, int y, int val){
	if((v[x][y + 1] != val && v[x][y-1] != val && v[x-1][y] != val && v[x+1][y] != val)){
		return true;
	}
	else{
		return false;
	}
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n + 2, vector<int>(m + 2, 0));
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  mat[x1][y1] = 1;
  mat[x1-1][y1] = 2;
  mat[x1 + 1][y1] = 2;
  mat[x1][y1 - 1] = 2;
  mat[x1][y1+1] = 2;

  mat[x2][y2] = 2;
  mat[x2-1][y2] = 1;
  mat[x2+1][y2] = 1;
  mat[x2][y2 - 1] = 1;
  mat[x2][y2+1] = 1;
  for(int i = 1; i <= n; i++){
  	for(int j = 1; j <= m; j++){
  		if((i == x1 && j == y1) || (i == x2 && j == y2)){
  			continue;
  		}
  		if(check(mat, i, j, 1)){
  			mat[i][j] = 1;
  		}
  		else if(check(mat, i, j, 2)){
  			mat[i][j] = 2;
  		}
  		else if(check(mat, i, j, 3)){
  			mat[i][j] = 3;
  		}
  		else if(check(mat, i, j, 4)){
  			mat[i][j] = 4;
  		}
  		else{
  			mat[i][j] = 5;
  		}
  	}
  }
  for(int i = 1; i <= n; i++){
  	for(int j = 1; j <= m; j++){
  		cout << mat[i][j] << " ";
  	}
  	cout << "\n";
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