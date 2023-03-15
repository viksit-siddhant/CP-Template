//CM when???
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define in2(x,y) int x,y; cin >> x >> y
#define in1(x) int x; cin >> x
#define all(x) x.begin(),x.end()
#define ordered_set(type) tree<type, null_type,less_equal<type>, rb_tree_tag,tree_order_statistics_node_update>
#define MOD 998244353
#define endl '\n'
typedef long long ll;
 
void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void print(vector<ll> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
 
void print(int c) {
    cout << c << endl;
}

void print(ll c) {
    cout << c << endl;
}

void print(int a, int b) {
    cout << a << " " << b << endl;
}

void print(ll a, ll b) {
    cout << a << " " << b << endl;
}

void print(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl; 
}

void print(string s) {
    cout << s << endl;
}

void print(pair<int,int> a) {
    cout << a.first << " " << a.second << endl;
}

ll p(ll a, int b) {
    if (b == 0) return 1;
    if (b%2 == 0) return p(a*a, b/2);
    return (a * p(a, b - 1));
}

ll p(ll a, int b, ll mod) {
    if (b == 0) return 1;
    if (b%2 == 0) return p(a*a % mod, b/2,mod);
    return (a * p(a, b - 1,mod))%mod;
}
 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

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

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    int cases = 0;
    if (cases) {
        int t;
        cin >> t;
        forn(i,t) {
            solve();
        }
    }
    else solve();
    return 0;
}
