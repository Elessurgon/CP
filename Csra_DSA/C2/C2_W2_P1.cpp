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

vl a;
ll ans = 0;
vpl ap;
ll parent(ll i) { return (i - 1) / 2; }
ll left(ll i) { return 2 * i + 1; }
ll right(ll i) { return 2 * i + 2; }

void siftup(ll i) {
	if (parent(i) >= 0 && a[parent(i)] > a[i]) {
		ans++;
		ap.pb({parent(i), i});
		swap(a[parent(i)], a[i]);
		if (parent(i) > 0) siftup(parent(i));
	}
	
}

void siftdown(ll i) {
	ll len = sz(a);
	bool l = false;
	ll index = i;
	if (left(i) < len && a[i] > a[left(i)]) {
		l = true;
		ans++;
		ap.pb({i, left(i)});
		index = left(i);
	}
	if (right(i) < len && a[i] > a[right(i)]) {
		if (l) {
			ans--;
			ap.pop_back();
		}
		ans++;
		ap.pb({i, right(i)});
		index = right(i);
	} 

	if (i != index) {
		swap(a[i], a[index]);
		siftdown(index);
	}
}

bool isMinHeap(ll i) {
	
	if (left(i) >= sz(a) && right(i) >= sz(a)) return true;
	if (left(i) < sz(a) && a[left(i)] < a[i]) {
		return false;
	}
	if (right(i) < sz(a) && a[right(i)] < a[i]) {
		return false;
	}
	return isMinHeap(left(i)) && isMinHeap(right(i));
}

void min_heap() {
	ll n;
	cin >> n;
	REP(i, 0, n - 1) {
		ll x; cin >> x;
		a.pb(x);
	}
	while(isMinHeap(0) == false) {
		REP_REV(i, n - 1, 0) {
			siftup(i);
		}
	}
	cout << ans << endl;
	REP(i, 0, ans - 1) {
		cout << ap[i].f << " " << ap[i].s << endl;
	}
}

void solve() {
	// ll ans = 0;
	// ll a, b, k;
	// cin >> a >> b >> k;
	// vpl ps(k);
	// REP(i, 0, k - 1) cin >> ps[i].f;
	// REP(i, 0, k - 1) cin >> ps[i].s;
	// sort(all(ps));
	// REP(i, 0, k - 1) {
	// 	REP_REV(j, k - 1, i) {
	// 			if (ps[i].f == ps[j].f || ps[i].s == ps[j].s) continue;
	// 			else ans++;
	// 	}
	// 	// ans += k - ind - 1;
	// }
	// cout << ans << endl;
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	min_heap();
	// freopen("split.in", "r", stdin);
	// freopen("split.out", "w", stdout);
	// ll t; cin >> t;
	// while (t--)
	// 	solve();
	return 0;
}
