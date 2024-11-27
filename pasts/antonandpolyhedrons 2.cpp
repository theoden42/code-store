
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
	int count = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "Tetrahedron")count += 4;
		if(s == "Cube" )count += 6;
		if(s == "Octahedron")count += 8;
		if(s == "Dodecahedron")count += 12;
		if(s == "Icosahedron")count += 20;

	}
	cout << count << "\n";
}


// "Tetrahedron" (without quotes), if the i-th polyhedron in Anton's collection is a tetrahedron.
// "Cube" (without quotes), if the i-th polyhedron in Anton's collection is a cube.
// "Octahedron" (without quotes), if the i-th polyhedron in Anton's collection is an octahedron.
// "Dodecahedron" (without quotes), if the i-th polyhedron in Anton's collection is a dodecahedron.
// // "Icosahedron

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