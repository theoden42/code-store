 
 /* @uthor: (g)theoden42 */
 
 #include <bits/stdc++.h>
 using namespace std;
 
 #define ll long long
 #define ld long double
 #define all(a) (a).begin(), (a).end()
 
 const int MAX_N = 1e5 + 5;
 const ll MOD = 1e9 + 7;
 const ll INF = 1e9;
 const ld EPS = 1e-9;
 
 void solve() {
     int n, m;
     cin >> n;
     vector<int> boys(n, 0);

     for(int i = 0; i < n; i++){
     	cin >> boys[i];
     }
     cin >> m;
     vector<int> girls(m, 0);
     for(int i = 0; i < m; i++){
     	cin >> girls[i];
     }
     sort(boys.begin(), boys.end());
     sort(girls.begin(), girls.end());
     int i = 0;
     int j = 0;
     int count = 0;
     while(i < n && j < m){
     	if(abs(girls[j] - boys[i]) <= 1){
     		count++;
     		i++;
     		j++;
     	}
     	else if(girls[j] < boys[i]){
     		j++;
     	}
     	else{
     		i++;
     	}
     }
     cout << count << "\n";

 }
 
 int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     int tc = 1;
     //cin >> tc;
     for (int t = 1; t <= tc; t++) {
         // cout << "Case #" << t << ": ";
         solve();
     }
 }