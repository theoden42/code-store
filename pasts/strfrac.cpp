#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

void solve() {
	ll p, q; cin >> p >> q;

	ll g = gcd(p, q);
	p /= g; q /= g;
	
	ll a = p*p;
	ll b= 4*q*q;

	if(a < b) {
		cout << "0 0";
		return;
	}

	long double c = sqrt(a - b);

	if((ll) c == c) {
		if(p < c) {
			long double d = sqrt((p + c)/2);

			if((ll) d == d && q%(ll)d == 0) {
				cout << (ll)d << " " << q/ (ll)d;
				return;
			}

		}
		else {
			long double d = sqrt((p+c)/2);

			if((ll)d == d && q%(ll)d == 0) {
				cout << (ll)d << " " << q/ (ll)d;
				return;
			}

			d = sqrt((p-c)/2);

			if((ll)d == d && q%(ll)d == 0) {
				cout << (ll)d << " " << q/ (ll)d;
				return;
			}
		}
	}
	else {
		cout << "0 0";
		return;
	}

	cout << "0 0";
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
    	solve();
    	cout << endl;
    }
}