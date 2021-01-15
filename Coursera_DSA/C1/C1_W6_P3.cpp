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

ll operate(ll n1, char op, ll n2) {
	switch (op) {
		case '+': return n1 + n2;
		case '-': return n1 - n2;
		default : return n1 * n2;;
	}
}

vector<ll> minMax(ll i, ll j, vvl dpMin, vvl dpMax, vector<char> op) {
	ll min = 1e8;
	ll max = -1e8;
	ll a, b, c, d;
	for(ll k = i; k < j; k++) {
		a = operate(dpMax[i][k], op[k], dpMax[k + 1][j]);
		b = operate(dpMax[i][k], op[k], dpMin[k + 1][j]);
		c = operate(dpMin[i][k], op[k], dpMax[k + 1][j]);
		d = operate(dpMin[i][k], op[k], dpMin[k + 1][j]);
		vl m = {a, b, c, d, min};
		vl M = {a, b, c, d, max};
		min = *min_element(all(m));
		max = *max_element(all(M));
	}
	return {min, max};
	
}

void solve() {
	string s;
	cin >> s;
	ll len = sz(s);

	vector<ll> d;
	vector<char> op;
	for(int i = 0; i < len; i += 2) {
		d.pb(s[i] - '0');
		if (i + 1 < len) op.pb(s[i + 1]);
	}
	ll n = sz(d);

	vvl dpMin(n, vector<ll>(n, 0));
	vvl dpMax(n, vector<ll>(n, 0));
	for(ll i = 0; i < n; i++) {
		dpMin[i][i] = d[i];
		dpMax[i][i] = d[i];
	}

	for(ll s = 1; s < n; s++) {		
		for(ll i = 0; i < n - s; i++) {
			ll j = i + s;
			vl ans = minMax(i, j, dpMin, dpMax, op);
			dpMin[i][j] = ans[0];
			dpMax[i][j] = ans[1];
		}
	}

	cout << dpMax[0][n - 1];
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
