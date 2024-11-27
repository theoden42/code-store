

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
const ll MOD = 1e12 + 7;
const ll INF = 1e9;

#define int long long

struct node { 
    int sum;
    int count;
    int child[26];
    node(){
        sum = 0;
        count = 0;
        for(int i = 0; i < 26; i++){
            child[i] = -1;
        }
    }
    node(int s, int c): sum(s), count(c){
        for(int i = 0; i < 26; i++){
            child[i] = -1;
        }
    }
};

struct Trie { 
    array<node, (int)1e6 + 5> nodes;
    int num_nodes;
    Trie() {    
        num_nodes = 1;
        nodes[0] = {0, 0};

    }

    void add(string &s){
        debug(s);
        int sz = s.size();
        int index = 0;
        nodes[index].sum += sz;
        nodes[index].count += 1; 
        for(int i = 0; i < sz; i++){
            if(nodes[index].child[s[i] - 'a'] == -1){
                // node temp = new node();
                int nindex = num_nodes;
                nodes[nindex] = {0, 0};
                num_nodes += 1;
                nodes[index].child[s[i] - 'a'] = nindex;
            } 
            index = nodes[index].child[s[i] - 'a'];
            nodes[index].sum += sz;
            nodes[index].count += 1;
        }
    }

    int findvalue(string& s, int n){
        int finalans = 0;

        stack<int> st;
        int vind = 0;
        int ind = 0;
        while(vind != -1){
            // debug(vind);
            st.push(vind);
            if(ind == s.size())
                break;
            vind = nodes[vind].child[s[s.size() - 1 - ind] - 'a'];
            if(vind != -1)
                ind += 1;
        }
        int al_sum = 0, al_count = 0;
        while(!st.empty()){
            auto index = st.top();
            st.pop();

            int newsum = nodes[index].sum - al_sum;
            int newcount = nodes[index].count - al_count;
            // debug(ind, newsum, newcount);
            finalans += newcount * (s.size() - ind) + newsum - newcount * (ind);

            al_sum = nodes[index].sum;
            al_count = nodes[index].count;
            ind -= 1;
            // debug(finalans);
        }
        return finalans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    Trie tr;

    for(int i = 0; i < n; i++){
        cin >> s[i];
        tr.add(s[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += tr.findvalue(s[i], n);
        debug(ans);
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}