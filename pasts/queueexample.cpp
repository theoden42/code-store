
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

    /* Similar to stacks we can create queue
    by specifying a data type within angular brackets */
	queue<int> q; 

	/* lets just get to the functions */

	// push() enters element at the last..
	q.push(5);
	q.push(6);
	q.push(7);
	//queue becomes [5, 6, 7]


	//pop() removes the element from the front of the queue
	q.pop();
	// queue becomes [6, 7]


	/* front() is used to get the element at the front
	 and back() to get the element at last */
	cout << q.front() << " " << q.back() << "\n";


	/* size() returns the total elements in the queue and empty()
	 returns whether the queue is empty or not */

	if(q.size() == 2){
		cout << "You count well!";
	}
	else{
		cout << "Don't worry, just program the counter.";
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