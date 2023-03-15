#include <bits/stdc++.h>
using namespace std;

class LCA {
    vector<int> tin, tout;
    vector<vector<int>> up;
    int timer;
    int n,l;

    void dfs(int v, int p, vector<vector<int>> &adj) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }    

    public:
    LCA(vector<vector<int>> &adj, int root) {
        n = adj.size();
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(l + 1));
        dfs(root, root, adj);
    }
    
};