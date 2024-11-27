
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


struct node{
    int min;
    int num;
};

struct segTree{
    int size;
    vector<node> arr;
    node inf;

    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        inf.min = 1e9 + 5;
        inf.num = 0;
        arr.assign(2 * size, inf);
    }

    void build(vector<int>& a){
        build(a, 0, 0, size);
    }
    void set(int index, int value){
        set(index, value, 0, 0, size);
    }
    node get(int l, int r){
        return get(l, r, 0, 0, size);
    }

    node combine(node a, node b){
        if(a.min < b.min){
            return a;
        }
        else if(b.min < a.min){
            return b;
        }
        else{
            node n;
            n.min = a.min;
            n.num = a.num + b.num;
            return n;
        }
    }

    void build(vector<int>& a, int x, int lx, int rx){

        debug(x, lx, rx);

        if(rx - lx == 1){
            if(lx < (int)a.size()){
                node temp;
                temp.min = a[lx];
                temp.num = 1;
                arr[x] = temp;
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
    }

    void set(int index, int value, int x, int lx, int rx){
        if(rx - lx == 1){
            node temp;
            temp.min = value;
            temp.num = 1;
            arr[x] = temp;
            return;
        }
        int m = (lx + rx) / 2;
        if(index < m){
            set(index, value, 2 * x + 1, lx, m);
        }else{
            set(index, value, 2 * x + 2, m, rx);
        }

        arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
    }

    node get(int l, int r, int x, int lx, int rx){  

        if(lx >= r || rx <= l)return inf;
        if(lx >= l && rx <= r)return arr[x];

        int mid = (lx + rx) / 2;


        node m1 = get(l, r, 2 * x + 1, lx, mid);
        node m2 = get(l, r, 2 * x + 2, mid, rx);

        return combine(m1, m2);
    }

};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
        cin >> ele[i];
    }
    segTree st;
    st.init(n);

    st.build(ele);

    // for(auto x: st.arr){
    //     cout << x.min << " " << x.num << "\n";
    // }


    for(int i = 1; i <= m; i++){
        int q, in, v;
        cin >> q >> in >> v;

        if(q == 1){
            st.set(in, v);
        }
        else{
            cout << st.get(in, v).min << " " << st.get(in, v).num << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}