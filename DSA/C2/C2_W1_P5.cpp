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

void test() {
    ll n = rand() % 10 + 1;
    ll m = rand() % n + 1;
    vl a(n);
    REP(i, 0, n - 1) {
        a[i] = rand() % 10000;
    }
    vl b, c;
    cout << "n = " << n << " m =  " << m << endl;
    cout << "a = ";
    REP(i, 0, n - 1) {
        cout << a[i] << " ";
    }
    cout << endl;
    // algorithm 1
    REP(i, 0, n - m) {
        ll ans = -1;
        REP(j, 0, m - 1) {
            ans = max(ans, a[i + j]);
        }
        b.pb(ans);
    }
    cout << "b = ";
    REP(i, 0, sz(b) - 1) {
        cout << b[i] << " ";
    }
    cout << endl;

    // algorithm 2
    if (m == 1) {
        REP(i, 0, n - 1) {
            c.pb(a[i]);
        }
    } else {
        deque<ll> q;
        ll ans = -1;
        ll index = -1;

        REP(i, 0, m - 1) {
            if (ans < a[i]) {
                ans = a[i];
                index = i;
                q.push_front(index);
            } else {
                while (a[q.back()] < a[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
        }

        c.push_back(a[q.front()]);
        REP(i, m, n - 1) {
            while (q.front() <= i - m) {
                q.pop_front();
            }
            if (sz(q) == 0) {
                q.push_front(i);
            } else if (a[i] > a[q.front()]) {
                q.clear();
                q.push_front(i);
            } else {
                while (sz(q) > 0 && a[q.back()] < a[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            c.push_back(a[q.front()]);
        }
    }

    cout << "c = ";
    REP(i, 0, sz(b) - 1) {
        cout << c[i] << " ";
    }
    cout << endl;

    // compare
    REP(i, 0, n - m) {
        if (b[i] != c[i]) {
            cout << "doesnt work\n";

            exit(0);
        }
    }
}

void solve() {
    ll n, m;
    cin >> n;
    vl a(n), c;
    REP(i, 0, n - 1) {
        cin >> a[i];
    }
    if (m == 1) {
        REP(i, 0, n - 1) {
            cout << a[i] << " ";
        }
        return;
    }
    cin >> m;

    if (m == 1) {
        REP(i, 0, n - 1) {
            c.pb(a[i]);
        }
    } else {
        deque<ll> q;
        ll ans = -1;
        ll index = -1;

        REP(i, 0, m - 1) {
            if (ans < a[i]) {
                ans = a[i];
                index = i;
                q.push_front(index);
            } else {
                while (a[q.back()] < a[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
        }

        c.push_back(a[q.front()]);
        REP(i, m, n - 1) {
            while (q.front() <= i - m) {
                q.pop_front();
            }
            if (sz(q) == 0) {
                q.push_front(i);
            } else if (a[i] > a[q.front()]) {
                q.clear();
                q.push_front(i);
            } else {
                while (sz(q) > 0 && a[q.back()] < a[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            c.push_back(a[q.front()]);
        }
    }
    // print answer
    REP(i, 0, sz(c) - 1) {
        cout << c[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("guess.in", "r", stdin);
    // freopen("guess.out", "w", stdout);
    ll i = 1;
    while (true) {
        cout << "i = " << i;
        test();
        i++;
    }
    // solve();
    return 0;
}
