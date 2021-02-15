#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (ll i = a; i <= b; i++)
#define REP_REV(i, a, b) for (ll i = a; i >= b; i--)
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

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

const ll MOD = 1e9 + 7;
const int INF = int(1e9);

bool isPrime(ll n) {
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

ll expon(ll a, ll b) {
    ll ans = 1;
    REP(i, 1, b) {
        ans *= a;
    }
    return ans;
}

void solve() {
    ll p = 263;
    ll m = 10007;
    string s, t;
    cin >> s >> t;
    ll S = sz(s), T = sz(t);
    vl pows(max(S, T));
    vl h(T + 1, 0);

    pows[0] = 1;
    REP(i, 1, sz(pows) - 1) {
        pows[i] = (pows[i - 1] * p) % m;
    }

    REP(i, 0, T - 1) {
        h[i + 1] = (h[i] + (((t[i] - 'a' + 1) + m) % m) * pows[i]) % m;
    }

    ll h_s = 0;
    REP(i, 0, S - 1) {
        h_s = (h_s + (((s[i] - 'a' + 1) + m) % m) * pows[i]) % m;
    }

    REP(i, 0, T - S) {
        ll h_t_string = (h[i + S] + m - h[i]) % m;
        if (((h_s + m) * pows[i]) % m == h_t_string) {
            if (s == t.substr(i, S)) {
                cout << i << " ";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("guess.in", "r", stdin);
    // freopen("guess.out", "w", stdout);
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
