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

ll hashString(string s, ll p, ll x, ll m) {
    ll h = 0;
    REP_REV(i, sz(s) - 1, 0) {
        h = (h * x + s[i]) % p;
    }
    h = (((h % p) + p) % p) % m;
    return h;
}

void solve() {
    ll p = 1000000007;
    ll x = 263;
    ll m, n;
    cin >> m >> n;
    vector<vector<string>> a(m);
    REP(i, 0, n - 1) {
        string s;
        cin >> s;
        if (s == "check") {
            ll i;
            cin >> i;
            REP_REV(j, sz(a[i]) - 1, 0) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        } else {
            string word;
            cin >> word;
            ll h = hashString(word, p, x, m);
            if (s == "add") {
                bool found = false;
                for (auto w : a[h]) {
                    if (w == word) {
                        found = true;
                        break;
                    }
                }
                if (!found) a[h].pb(word);
            } else if (s == "del") {
                a[h].erase(remove(a[h].begin(), a[h].end(), word), a[h].end());
            } else if (s == "find") {
                bool found = false;
                for (auto w : a[h]) {
                    if (w == word) {
                        found = true;
                        break;
                    }
                }
                if (found)
                    cout << "yes\n";
                else
                    cout << "no\n";
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
