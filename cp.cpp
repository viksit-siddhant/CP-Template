#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define foreach(i,v) for (auto i : v)
#define in3(x,y,z) int x,y,z; cin >> x >> y >> z
#define in2(x,y) int x,y; cin >> x >> y
#define in1(x) int x; cin >> x
#define instr1(x) string x; cin >> x
#define instr2(x,y) string x,y; cin >> x >> y
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ordered_set(type) tree<type, null_type,less_equal<type>, rb_tree_tag,tree_order_statistics_node_update>
#define MOD 998244353
#define invec(a,k) vector<ll> a(k);for (int i = 0; i < k;i++) cin >> a[i]
#define valid(x,n) 0 <= x && x < n
typedef long long ll;

template<typename T>
void print_container(const T& container) {
    for (const auto& elem : container) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void print_2d_container(const T& container) {
    for (const auto& row : container) {
        print_container(row);
    }
}

template<typename... Args>
void print(const Args&... args) {
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

template<typename T>
void print(const std::vector<T>& vec) {
    print_container(vec);
}

template<typename T>
void print(const std::vector<std::vector<T>>& vec) {
    print_2d_container(vec);
}

template<typename T>
void print(const std::set<T>& s) {
    print_container(s);
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

template <typename T>
vector<vector<T>> matrix(int n, int m) {
    return vector<vector<T>>(n, vector<T>(m));
}
template <typename T>
vector<vector<T>> matrix(int n, int m, T val) {
    return vector<vector<T>>(n, vector<T>(m, val));
}

void solve() {

}
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif    
    int cases = 1;
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