#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define REP(i, a, b) for (ll i = a; i <= b; i++)
#define REP_REV(i, a, b) for (ll i = a; i >= b; i--)
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl "\n"

#define pb push_back
#define rsz resize
#define f first
#define s second
#define mp make_pair

using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vc = vector<char>;
using ull = unsigned int64_t;
using pi = pair<int, int>;
using vl = vector<int64_t>;
using pl = pair<int64_t, int64_t>;
using vpl = vector<pair<int64_t, int64_t>>;
using msl = map<string, int64_t>;
using vvl = vector<vector<int64_t>>;

#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template <class T>
void DBGvec(vector<T> a) {
    for (T i : a) cerr << i << " ";
    cerr << endl;
}
template <class T>
void DBGvec_pair(vector<T> a) {
    for (T i : a) cerr << "{" << i.f << " " << i.s << "} ";
    cerr << endl;
}
template <class K, class P>
void DBGmap(map<K, P> a) {
    for (auto i : a) cerr << "{" << i.f << " " << i.s << "} ";
    cerr << endl;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e18);

bool isPrime(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned long long factorial(int n) {
    const unsigned int M = MOD;
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f * i) % M;
    return f;
}

ll expon(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    ll a1 = (a + b + 1) / 2, b1 = (a + b) / 2;
    ll a2 = (a + b) / 2, b2 = (a + b + 1) / 2;
    set<ll> s;
    REP(x, 0, a + b) {
        ll y = a - (a1 - x);
        if (y >= 0 && x + y >= 0 && x + y <= a + b && a1 >= x && b >= x) {
            s.insert(x + y);
        }

        y = a - (a2 - x);
        if (y >= 0 && x + y >= 0 && x + y <= a + b && a2 >= x && b >= x) {
            s.insert(x + y);
        }
    }

    cout << sz(s) << endl;
    for (ll x : s) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif

    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
        solve();

#ifdef _DEBUG
    cerr << "\nTIME = " << clock() - tt << endl;
    tt = clock();
#endif
    return 0;
}