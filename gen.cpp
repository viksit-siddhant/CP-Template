#include "testlib.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int q = atoi(argv[2]);
    int t = atoi(argv[3]);
    cout << n << " " << q << endl;
    for (int i = 0; i < n;i++) {
        int a = rnd.next(0,1000000000);
        cout << a;
        if (i != n-1) cout << " ";
    }
    cout << endl;
    int p[n];
    for (int i = 1; i < n;i++) {
        p[i] = rnd.wnext(i,t);
    }
    vector<int> perm = rnd.perm(n);

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    shuffle(edges.begin(), edges.end());
    for (auto edge: edges)
        println(edge.first + 1, edge.second + 1);
    for (int i = 0; i < q;i++) {
        int a = rnd.next(2);
        if (a) {
            int b = rnd.next(1,n);
            int c = rnd.next(0,1000000000);
            cout << 1 << " " << b << " " << c << endl;
        } else {
            int b = rnd.next(1,n);
            cout << 2 << " " << b << endl;
        }
    }
    return 0;
}