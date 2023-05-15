
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
    int a, b;
    cin >> a >> b;
    if(a <= b){
    	int suma = 0;
    	int sumb = 0;
    	set<int> sa;
    	set<int> sb;
    	int k = 1; 
    	while(k <= b){
    		sb.insert(k);
    		sumb += k;
    		b -= k;
    		k++;
    	}	
    	while(k <= a){
    		sa.insert(k);
    		suma += k;
    		a -= k;
    		k++;
    	}
    	// for(auto& x: sa){
    	// 	cout << x << " ";
    	// }
    	// cout << "\n";
    	// for(auto& x: sb){
    	// 	cout << x << " ";
    	// }
    	// cout << "\n";
    	// cout << a << " " << b << "\n";
    	auto x = upper_bound(all(sb), a);
    	while(x != sb.begin()){
    		x--;
    		if(*x > a){
    			break;
    		}
    		b += *x;
    		sb.erase(*x);
    		a -= *x;
    		sa.insert(*x);
    		x = upper_bound(all(sb), a);
    	}	
    	if(b >= k){
    		sb.insert(k);
    	}
    	cout << sa.size() << "\n";
    	for(auto& x: sa){
    		cout << x << " ";
    	}
    	cout << "\n";
    	cout << sb.size() << "\n";
    	for(auto& x: sb){
    		cout << x << " ";
    	}
    	cout << "\n";
    }
    else{
    	int tem = b;
    	b = a;
    	a = tem;
    	int suma = 0;
    	int sumb = 0;
    	set<int> sa;
    	set<int> sb;
    	int k = 1; 
    	while(k <= b){
    		sb.insert(k);
    		sumb += k;
    		b -= k;
    		k++;
    	}	
    	while(k <= a){
    		sa.insert(k);
    		suma += k;
    		a -= k;
    		k++;
    	}
    	auto x = sb.upper_bound(a);
    	while(x != sb.begin()){
    		x--;
    		if(*x > a){
    			break;
    		}
    		b += *x;
    		sb.erase(*x);
    		a -= * x;
    		sa.insert(*x);
    	}	
    	if(b >= k){
    		sb.insert(k);
    	}
    	cout << sb.size() << "\n";
    	for(auto& x: sb){
    		cout << x << " ";
    	}
    	cout << "\n";
    	cout << sa.size() << "\n";
    	for(auto& x: sa){
    		cout << x << " ";
    	}
    	cout << "\n";
    }
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