#include <bits/stdc++.h>
using namespace std;

//Return vector of all primes less than n
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> isPrime(n, true);
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}