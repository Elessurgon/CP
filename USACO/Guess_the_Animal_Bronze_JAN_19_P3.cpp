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

vl dsu;
vl tbls;

ll find_set(ll i) {
    if (i == dsu[i])
        return i;
    else {
        return dsu[i] = find_set(dsu[i]);
    }
}

void union_set(ll i, ll j) {
    ll r1 = find_set(i);
    ll r2 = find_set(j);
    if (r1 != r2) {
        dsu[r2] = r1;
        tbls[i] += tbls[j];
        tbls[j] = tbls[i];
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<string>> animals;
    REP(i, 0, n - 1) {
        string animal;
        cin >> animal;
        ll k;
        cin >> k;
        vector<string> chara;
        REP(j, 0, k - 1) {
            string s;
            cin >> s;
            chara.pb(s);
        }
        sort(all(chara));
        animals.pb(chara);
    }
    ll ans = 0;
    REP(i, 0, n - 1) {
        REP(j, i + 1, n - 1) {
            ll com = 0;
            REP(k, 0, sz(animals[i]) - 1) {
                REP(l, 0, sz(animals[j]) - 1) {
                    if (animals[i][k] == animals[j][l]) {
                        com++;
                    }
                }
            }
            ans = max(ans, com);
        }
    }
    cout << ans + 1;
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
