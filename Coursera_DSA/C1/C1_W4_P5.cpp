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

const ll MOD = 1e9 + 7;
const int INF = int(1e9);

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
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

ll binarySearch(ll num, vector<ll> a) {
	ll left = 0, right = sz(a) - 1;
	ll mid = (left + right) / 2;
	while(left <= right) {
		if (a[mid] == num) return mid;
		else if (a[mid] < num) left = mid + 1;
		else right = mid - 1;
		mid = (left + right) / 2;
	}
	return -1;
}

int binarySearchRange(int point, vector<pair<int, int>> segs) {
	ll left = 0, right = sz(segs) - 1;
	ll mid = (left + right) / 2;
	while(left <= right) {
		if (segs[mid].f <= point && point <= segs[mid].s) return mid;
		else if (segs[mid].s < point) left = mid + 1;
		else right = mid - 1;
		mid = (left + right) / 2;
	}
	return -1;
}

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	if (a.f == b.f) return a.s > b.s;
	return a.f < b.f;
}

vector<int> better(vector<pair<int, int>> segs, vector<int> pts) {
  	sort(all(segs), cmp);
	vector<int> ints(sz(pts));
	int overlap = 0;
	map<int, int> m;

	REP(i, 0, sz(segs) - 1)  {
		if (segs[i].s == 0) m[segs[i].f] = overlap;
		else overlap += segs[i].s;
	}
	
	REP(i, 0, sz(ints) - 1) {
		ints[i] = m[pts[i]];
	}
	return ints;
}

void solve() {
  int s, p;
  cin >> s >> p;
  
  vector<int> pts(p);
  vector<pair<int, int>> segs;

  
  REP(i, 0, s - 1) {
  	int st, ed;
  	cin >> st >> ed;
    segs.pb({st, 1});
    segs.pb({ed, -1});
  }

  REP(i, 0, p - 1) {
    cin >> pts[i];
    segs.pb({pts[i], 0});
  }
  
  vector<int> ans2 = better(segs, pts);
  REP(k, 0, p - 1) {
    cout << ans2[k] << " ";
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
