#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTree {
    public:
    long long int n;
    vector<T> tree;
    function<T(T, T)> f = [](T a, T b) { return a + b; };

    void build(vector<T> arr) {
        n = arr.size();
        tree.resize(2*n);
        for (int i = n;i < 2*n;i++) {
            tree[i] = arr[i-n];
        }
        for (int i = n-1;i > 0;i--) {
            tree[i] = f(tree[i<<1],tree[i<<1|1]);
        }
    }

    SegTree(vector<T> arr) {
        build(arr);
    }

    SegTree(vector<T> arr, function<T(T, T)> func) {
        f = func;
        build(arr);
    }

    T rangeQuery(T l, T r) {
        T res = 0;
        for (l += n, r += n;l < r;l >>= 1, r >>= 1) {
            if (l&1) res = f(res, tree[l++]);
            if (r&1) res = f(res, tree[--r]);
        }
        return res;
    }

    void pointUpdate(int p, T val) {
        for (tree[p += n] = val;p > 1;p >>= 1) {
            tree[p>>1] = f(tree[p],tree[p^1]);
        }
    }

    T pointQuery(int p) {
        T res = 0;
        for (tree[p += n] = val;p > 0;p >>= 1) {
            res = f(res, tree[p]);
        }
        return res;
    }

    void rangeUpdate(int l, int r, T val) {
        for (l += n, r += n;l < r;l >>= 1, r >>= 1) {
            if (l&1) tree[l++] += val;
            if (r&1) tree[--r] += val;
        }
    } 
    
};