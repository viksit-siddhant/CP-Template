#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    int nodes;
    int connectedComp;
    vector<int> parent;
    vector<int> size;
    vector<bool> loop;

    DSU(int n) {
        nodes = n;
        connectedComp = n;
        parent.resize(n + 1);
        loop.resize(n+1);
        size.assign(n + 1, 1);
        make_set();
    }

    void make_set() {
        for(int i = 1; i <= nodes; i++) {
            parent[i] = i;
            loop[i] = false;
        }
    }

    int find(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void merge(int v, int u) {
        v = find(v);
        u = find(u);
        if(v != u) {
            if(size[v] < size[u]) swap(v, u);
            parent[u] = v;
            size[v] += size[u];
            connectedComp--;
            if (loop[v] || loop[u]) loop[v] = true;
        } 
    }

    int setSize(int v) {
        v = find(v);
        return size[v];
    }
};