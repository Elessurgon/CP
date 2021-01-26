#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (ll i = a; i <= b; i++)
#define REP_REV(i,a,b) for (ll i = a; i >= b; i--)
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
using ull = unsigned int64_t ;
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
	for(ll i = 2; i * i <= n; i++) {
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
        f = (f*i) % M;  
    return f;
}

void solve() {
	ll n, m;
	cin >> n >> m;
    
    struct Comp {
        bool operator()(const pair<ll, ll> &a, const pair<ll, ll>  &b) {
            if (a.f != b.f) return a.f > b.f;
            else return a.s > b.s;
        }
    };

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Comp> q;
	REP(i, 0, n - 1) {
		q.push({0, i});
	}
	REP(i, 0, m - 1) {
		ll inp; cin >> inp;
		ll finish = inp + q.top().f; 
		ll id = q.top().s;
		cout << q.top().s << " " << q.top().f << endl;
		q.pop();
		q.push({finish, id});
	}
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("split.in", "r", stdin);
	// freopen("split.out", "w", stdout);
	// ll t; cin >> t;
	// while (t--)
		solve();
	return 0;
}
