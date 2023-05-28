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
#define invec(a,k) vector<long long int> a(k);for (int i = 0; i < k;i++) cin >> a[i]
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
    
void print(string s, int c) {
    cout << s << " " << c << endl;
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
    
// floor(sqrt(x))
ll square_root(ll x) {
    ll l = 0, r = x;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (mid * mid <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    in2(n,k);
    string s;
    ll ans = 1;
    ll mod = 998244353;
    cin >> s;
    vector<int> ones;
    ones.push_back(-1);
    forn(i,n) {
        if (s[i] == '1') ones.push_back(i);
    }
    ones.push_back(n);
    if (k == 0 || k > ones.size()-2) {
        print(1);
        return;
    }
    vector<ll> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    auto ncr = [&](int n, int r) {
        if (n <= 0) return (ll)0;
        ll ans = fact[n];
        ans = (ans * p(fact[r], mod - 2, mod)) % mod;
        ans = (ans * p(fact[n-r], mod - 2, mod)) % mod;
        return ans;
    };
    int l = 1, r = k;
    while (r < ones.size() - 1) {
        ans += ncr(ones[r+1] - 1 - ones[l-1] - 1 + 1,k) - 1;
        if (l > 1) {
            ans -=  ncr(ones[r] - 1 - (ones[l-1] + 1) + 1,k-1) - 1;
        }
        ans = (ans + mod) % mod;
        l++;
        r++;
    }
    print(ans);
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