#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& t, int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = new_val; 
    } else {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(t, 2*v, tl, tm, pos, new_val);
        else
            update(t, 2*v+1, tm+1, tr, pos, new_val);
        t[v] = t[2*v] + t[2*v+1];
    }   
}

int sum(vector<int> t, int v, int tl, int tr, int l, int r) {
    if(l > r)
        return 0;

    if(l == tl && r == tr)
        return t[v]; 

    int tm = (tl + tr)/2;
    
    return sum(t, 2*v, tl, tm, l, min(r, tm)) + sum(t, 2*v+1, tm+1, tr, max(tm+1, l), r);
}

pair<int, int> alloc(vector<int>& t, int x, int v, int tl, int tr) {
    if(tl == tr)
        return {x == 1 && t[v] == 0? tl : -1, t[v]}; 

    int tm = (tl + tr)/2;
    auto bl = alloc(t, x, 2*v, tl, tm);
    if(bl.first != -1)
        return bl;
    auto br = alloc(t, x, 2*v+1, tm+1, tr);
    if(br.first != -1)
        return br;

    if(bl.second + br.second == 0 && x <= tr-tl+1)
        return {tl, bl.second+br.second};

    return {-1, bl.second + br.second};
}

void buildTree(vector<int>& t, vector<int> a, int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];   
    } else {
        int tm = (tl + tr)/2;
        buildTree(t, a, 2*v, tl, tm);
        buildTree(t, a, 2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}


vector<int> solution(vector<int> memory, vector<vector<int>> queries) {
    int n = memory.size();
    vector<int> t;
    t.resize(4 * n);
    buildTree(t, memory, 1, 0, n - 1);

    map<int, int> blocks;

    vector<int> res;
    for (const auto& q : queries) {
        int tmp = -1;
        if (q[0] == 0) {
            auto p = alloc(t, q[1], 1, 0, n - 1);
            if (p.first != -1) {
                tmp = p.first;
                blocks[p.first] = q[1];
                for (int pos = p.first; pos < p.first + q[1]; pos++)
                    update(t, 1, 0, n - 1, pos, 1);
            }
        } else {
            int l = q[1], r = q[1];
            if (memory[q[1]] == 1) {
                tmp = 1;
            } else if (blocks.find(q[1]) != blocks.end()) {
                tmp = blocks[q[1]];
                r += tmp;
            }

            if (tmp != -1) {
                for (int i = l; i <= r; i++)
                    update(t, 1, 0, n - 1, i, 0);
            }
        }
        res.push_back(tmp);
    }

    return res;
}
