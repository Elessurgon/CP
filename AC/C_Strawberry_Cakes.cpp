// link to the problem --> https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c

#include <bits/stdc++.h>

using namespace std;

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

const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max();

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
void DBGvec_pair(vector<T> a) {
    for (T i : a) cerr << "{" << i.f << " " << i.s << "} ";
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
    ll r, c, k;
    cin >> r >> c >> k;
    vvl s(r, vl(c, 0));
    ll cnt = 1;
    REP(i, 0, r - 1) {
        REP(j, 0, c - 1) {
            char x;
            cin >> x;
            if (x == '#') {
                s[i][j] = cnt;
                cnt++;
            }
        }
    }

    REP(i, 0, r - 1) {
        REP(j, 1, c - 1) {
            if (s[i][j] == 0) {
                s[i][j] = s[i][j - 1];
            }
        }
    }
    REP(i, 0, r - 1) {
        REP_REV(j, c - 2, 0) {
            if (s[i][j] == 0) {
                s[i][j] = s[i][j + 1];
            }
        }
    }

    REP(j, 0, c - 1) {
        REP(i, 1, r - 1) {
            if (s[i][j] == 0) {
                s[i][j] = s[i - 1][j];
            }
        }
    }
    REP(j, 0, c - 1) {
        REP_REV(i, r - 2, 0) {
            if (s[i][j] == 0) {
                s[i][j] = s[i + 1][j];
            }
        }
    }

    REP(i, 0, r - 1) {
        REP(j, 0, c - 1) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
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

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

#ifdef _DEBUG
    cerr << "\nTIME = " << clock() - tt << endl;
    tt = clock();
#endif
    return 0;
}