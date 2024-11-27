
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
   
   /* empty stack */
   stack<int> st;



   //push() function is used to insert element into a stack
   st.push(5);
   st.push(6); 
   /* stack is now [5, 6] */


   //pop() function is used to take out the last inserted element from a stack
   st.pop();
   /* stack is now [5] */


   //top() returns the last entered element
   cout << st.top() << "\n";
   /* gives 5 as output */


   st.pop();

   //empty() return whether the stack is empty or not
   if(st.empty()){
   		cout << "We are done with the implementation !!!";
   }
   else{
   		cout << "you can't be serious!";
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