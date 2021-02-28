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

ll n, m;
map<ll, vl> g;
vector<bool> visited;
ll a, b;

void dfs(ll u) {
    visited[u] = true;
    for (ll v : g[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    ll ans = 0;
    REP(i, 0, m - 1) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i, 0, n) {
        visited.pb(false);
    }
    REP(i, 1, n) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
