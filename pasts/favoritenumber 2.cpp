
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int a[750000 + 5];
   // memset(a, 1e18 + 5, sizeof(a));
    int n = 0;

    int x;
    bool f = false;
    while(1){

    	cout << "next" << endl;
    	cin >> x;
    	if(x == -1){
    		f = true;
    		break;
    	}
    	else{
    		if(n > 750000 + 5)
    			break;
    	 	a[n] = x;
  			n++;
    	}
    }
    if(!f){

    	sort(a, a + n);
    int a1 = -1, b = -1, c = -1, acnt, bcnt, ccnt;
    int count = 1;
    for(int i = 1; i < n; i++){
    	if(a[i] == a[i - 1]){
    		count++;
    	}
    	else{
    		count = 1;
    	}
    	if(count >  n / 4){
    		if(a1 == -1) { 
    			a1 = a[i]; acnt = count;}
    		else if(b == -1) {b = a[i]; bcnt = count;}
    		else {c = a[i]; ccnt = count;}
    	}
    }

    if(f) {
    	while(1) {
    		cout << "next" << endl;
    		cin >> x;

    		if(x == -1) {
    			break;
    		}

    		if(x == a1) {
    			acnt++;
    		}
    		else if(x == b) bcnt++;
    		else if(x == c) ccnt++;
    	}
    

    if(acnt > bcnt && acnt > ccnt){
    	cout << a << endl;
    }
     else  if(bcnt > acnt && bcnt > ccnt){
    	cout << b << endl;
    }
    else if(ccnt > acnt && ccnt > bcnt){
    	cout << c << endl;
    }
    return;
}
    }

    else{
    	sort(a, a + n);
    // int a1 = -1, b = -1, c = -1, acnt, bcnt, ccnt;
    int count = 1;
    for(int i = 1; i < n; i++){
    	if(a[i] == a[i - 1]){
    		count++;
    	}
    	else{
    		count = 1;
    	}
    	if(count >  n / 2){
    		 cout << a[i] << endl;
    		 return;
    	}
    }
	}
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   // int tc = 1;
    //cin >> tc;
    //for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
 //   }
}