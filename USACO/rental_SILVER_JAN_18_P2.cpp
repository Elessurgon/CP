#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REP_REV(i,a,b) for (int i = a; i >= b; i--)
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define pb push_back
#define rsz resize
#define f first
#define s second
#define mp make_pair

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vc = vector<char>;
using ull = unsigned long long ;
using pi = pair<int, int>;
using vl = vector<long long>;
using pl = pair<long long, long long>;
using vpl = vector<pair<long long, long long>>;
using msl = map<string, long long>;
using vvl = vector<vector<long long>>;

ll MOD = 1e9 + 7;
const int INF = int(1e9);

struct Rect {
	ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	ll area() { return (x2 - x1) * (y2 - y1); }
};

Rect intersect(Rect p, Rect q) {
	Rect inter;
	inter.x1 = max(p.x1, q.x1);
	inter.y1 = max(p.y1, q.y1);
	inter.x2 = min(p.x2, q.x2);
	inter.y2 = min(p.y2, q.y2);
	if (inter.x1 >= inter.x2 || inter.y1 >= inter.y2) {
		Rect empty;
		return empty;
	}
	return inter;
}

bool iscovered(int x, int y, int x1, int y1, int x2, int y2) {
	return (x <= x2 && x >= x1 && y <= y2 && y >= y1);
}	

bool isPrime(int n) {
	if (n == 2) return true;
	for(int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
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
	int n,m,r;
	cin >> n >> m >> r;
	vi c(n);
	vector<pair<int, int>> store;
	vi rent(r);
	
	REP(i, 0, n - 1) cin >> c[i];
	REP(i, 0, m - 1) {
		int q, p;
		cin >> q >> p;
		store.pb({p, q});
	}
	REP(i, 0, r - 1) cin >> rent[i];
	
	sort(rall(c));
	sort(rall(store));
	sort(rall(rent));
	
	vl cum(r + 1);
	REP(i, 0, r - 1) cum[i + 1] = cum[i] + rent[i];

	ll ans = 0;
	ll milk = 0;
	ll rnt = 0;
	int curr = 0;
	REP(i, 0,  n - 1) {
		int litres = c[i];
		while(curr < m) {
			int rest = min(litres, store[curr].s);
			milk += rest * store[curr].f;
			store[curr].s -= rest;
			litres -= rest;
			if (litres == 0) break;
			 else curr++;
		}

		int left = n - i - 1;

		if (left >= sz(cum)) rnt = cum[sz(cum) - 1];
		else rnt = cum[left];
		
		ans = max(ans, rnt + milk);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("rental.in", "r", stdin);
	//freopen("rental.out", "w", stdout);
	// ll t; cin >> t;
	// while (t--)
		solve();
	return 0;
}
