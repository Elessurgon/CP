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

ll height(map<ll, vl> m, ll n ,ll h) {
	ll h1 = h;
	// debug(h)
	// debug(n)
	if (sz(m[n]) == 0) return h;
	else {
		for(ll x : m[n]) {
			h = max(h, height(m, x, h1 + 1));
		}	
	}
	return h;
}

void solve() {
	ll n;
	cin >> n;
	map<ll, vl> m;
	ll root = -1;

	REP(i, 0, n - 1) {
		ll node;
		cin >> node;
		if (node == -1) root = i;
		else m[node].pb(i);
	}

	// Online judge Stack Overflow problems
	// ll h = height(m, root, 1);
	// cout << h;

	queue<ll> nodes;
	for(auto x : m[root]) {
		nodes.push(x);		
	}
	ll h = 1;
	while(!nodes.empty()) {
		vl children;
		while(!nodes.empty()) {
			children.push_back(nodes.front());
			nodes.pop(); 
		}
		for(auto child : children) {
			for(auto x : m[child]) {
				nodes.push(x);
			}
		}
		h++;
	}
	cout << h;
 	
	// for(auto x : m) {
	// 	cout << sz(m[x.f]) << " ";
	// 	cout << x.f << " -> ";
	// 	REP(i, 0, sz(m[x.f]) - 1) {
	// 		cout << m[x.f][i] << " ";
	// 	}
	// 	cout << endl;
	// }

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
