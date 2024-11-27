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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> front;
    vector<int> back;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	if(mp.find(ele[i]) == mp.end()){
    		mp[ele[i]] = 1;
    	}
    	else{
    		back.push_back(i);
    		mp[ele[i]]++;
    	}
    }
    mp.clear();
    for(int i = n - 1; i >= 0; i--){
    	if(mp.find(ele[i]) == mp.end()){
    		mp[ele[i]] = 1;
    	}
    	else{
    		front.push_back(i);
    		mp[ele[i]]++;
    	}
    }
    sort(front.begin(), front.end());
    sort(back.begin(), back.end());

    deque<int> arr;

    deque<int> f;
    deque<int> b;
    for(auto& x: front){
    	f.push_back(x);
    }
    for(auto& x: back){
    	b.push_back(x);
    }
  //   int count1 = 0;
  //   int count2 = 0;
  //   // stimulating moving from left first;
  //   int fsize = 0;
  //   int bsize = 0;

  //   // for(auto& y : f){
  //   // 	cout << y << " ";
  //   // }
  //   // cout << "\n";
  //   // for(auto& z : b){
  //   // 	cout << z << " ";
  //   // }
  //   // cout << "\n";

 	// while(f.size() > 0){
 	// 	if(f.front() < bsize + b.front()){
 	// 		if(f.front() == b.front()){
 	// 			b.pop_front();
 	// 		}
 	// 		count1++;
 	// 		bsize++;
 	// 		f.pop_front();
 	// 	}
 	// 	else{
 	// 		count1 += bsize + b.front();
 	// 		break;
 	// 	}
 	// }
 	// f.clear();
 	// b.clear();
 	// for(auto& x: front){
  //   	f.push_back(x);
  //   }
  //   for(auto& x: back){
  //   	b.push_back(x);
  //   }
  //   for(auto& y : f){
  //   	cout << y << " ";
  //   }
  //   cout << "\n";
  //   for(auto& z : b){
  //   	cout << z << " ";
  //   }
  //   cout << "\n";

 	// //stimulating right first
 	// while(b.size() > 0){
 	// 	if(b.back() < fsize + f.back()){
 	// 		if(f.back() == b.back()){
 	// 			f.pop_back();
 	// 		}
 	// 		count2++;
 	// 		fsize++;
 	// 		b.pop_front();
 	// 	}
 	// 	else{
 	// 		count2 += fsize + f.front();
 	// 		break;
 	// 	}
 	// }
 	// cout << min(count1, count2) << "\n";
 	int i = 0;
 	int j = n - 1;
 	int frcount = 0;
 	int bacount = 0;
 	for(auto& x : ele){
 		arr.push_back(x);
 	}

 	int count = 0;
  	while(mp[arr.front()] >= 2 || mp[arr.back()] >= 2){
  		if(mp[arr.front()] >= 2){
  			count++;
  			mp[arr.front()] -= 1;
  			arr.pop_front();
  			bacount++;
  		}
  		else {
  			count++;
  			mp[arr.back()] -= 1;
  			arr.pop_back();
  			frcount++;
  		}
  	}
  	int count1 = 0;
  	int count2 = 0;
  	map<int, int> enc;
  	for(auto& x : arr){
  		
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