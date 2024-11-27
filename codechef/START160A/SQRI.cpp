

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct Point {
    double x, y;
};

double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}

Point findIntersection(Point p1, Point p2, Point q1, Point q2) {
    // Calculate the coefficients for both lines
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1 * p1.x + b1 * p1.y;

    double a2 = q2.y - q1.y;
    double b2 = q1.x - q2.x;
    double c2 = a2 * q1.x + b2 * q1.y;

    // Calculate the determinant
    double det = determinant(a1, b1, a2, b2);

    if (fabs(det) < 1e-12) {  
        return {-1, -1};
    } else {
        // Use Cramer's rule to solve for the intersection point
        double x = determinant(c1, b1, c2, b2) / det;
        double y = determinant(a1, c1, a2, c2) / det;
        return {x, y};
    }
}


void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    Point one = findIntersection({0, y + b}, {x, y}, {a, y + b}, {x + b, y});
    Point two = findIntersection({x + b, 0}, {x, y}, {x + b, a}, {x, y + b});
    Point three = findIntersection({x, 0}, {x + b, y}, {x, a}, {x + b, y + b});
    Point four = findIntersection({0, y}, {x, y + b}, {a, y}, {x + b, y+ b});
    auto check = [&](Point p){
        return (p.x >= 0ll && p.x <= a && p.y >= 0 && p.y <= a);
    };
    if(check(one) || check(two) || check(three) || check(four)){
        cout << "yes\n";
    } else {
        cout << "no\n";
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