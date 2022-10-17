#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define REP(i, a, b) for (ll i = a; i <= b; i++)
#define REP_REV(i, a, b) for (ll i = a; i >= b; i--)
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
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
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
using min_heapll = priority_queue<ll, vector<ll>, greater<ll>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max();
vl dx = {0, 0, 1, -1};
vl dy = {1, -1, 0, 0};
vc dir = {'R', 'L', 'D', 'U'};

vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

#define DBG(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

template <class T>
void DBGvec(vector<T> a) {
    for (T i : a) cerr << i << " ";
    cerr << endl;
}
template <class T>
void DBGmat(vector<vector<T>> a) {
    for (vector<T> v : a) {
        for (T i : v) {
            cerr << i << " ";
        }
        cerr << endl;
    }
    cerr << endl;
}
template <class T>
void DBGvec_pair(vector<T> a) {
    for (T i : a) cerr << "{" << i.f << " " << i.s << "} ";
    cerr << endl;
}
template <class T>
void DBGmset(multiset<T> a) {
    for (T i : a) cerr << i << " ";
    cerr << endl;
}
template <class T>
void DBGset(set<T> a) {
    for (T i : a) cerr << i << " ";
    cerr << endl;
}
template <class K, class P>
void DBGmap(map<K, P> a) {
    for (auto i : a) cerr << "{" << i.f << " " << i.s << "} ";
    cerr << endl;
}

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
    ll q;
    cin >> q;
    vl let(26);
    vl a(26), b(26);
    a[0] = 1;
    b[0] = 1;
    REP(_, 0, q - 1) {
        ll d, k;
        string x;
        cin >> d >> k >> x;
        REP(i, 0, sz(x) - 1) {
            if (d == 1) {
                a[(x[i] - 'a')] += k;
            } else {
                b[(x[i] - 'a')] += k;
            }
        }

        // DBGvec(a);
        // DBGvec(b);

        bool done = false;
        REP(i, 1, 25) {
            if (b[i] > 0) {
                done = true;
            }
        }

        // DBG(done);

        if (done)
            cout << "YES\n";
        else {
            bool ok = false;
            REP(i, 1, 25) {
                if (a[i] > 0) ok = true;
            }
            // DBG(ok);
            if ((a[0] <= b[0] && ok) || a[0] >= b[0]) {
                cout << "NO\n";
                // DBG("NO");
            } else {
                cout << "YES\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif

    // freopen("cardgame.in", "r", stdin);
    // freopen("cardgame.out", "w", stdout);

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