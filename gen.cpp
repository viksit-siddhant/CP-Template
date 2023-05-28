#include "testlib.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    cout << n << " " << k << endl;
    int lim = 1e9;
    for (int i = 0; i < n;i++) {
        int a = rnd.next(1,lim);
        cout << a;
        if (i != n-1) cout << " ";
    }
    cout << endl;
    return 0;
}