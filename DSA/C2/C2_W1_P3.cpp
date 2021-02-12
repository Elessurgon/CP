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
	ll s, n; 
	cin >> s >> n;
	if (n > 0) {
		queue<ll> buffer;
		vl start_time(n);
		REP(i, 1, s) {
			ll a, p;
			cin >> a >> p;
			if (i > 1 && a > buffer.back()) start_time[i - 1] = a;
			else if (i > 1) start_time[i - 1] = buffer.back();
			else start_time[i - 1] = a;
			buffer.push(start_time[i - 1] + p);
		}
		
		REP(i, s + 1, n) {	
			ll a, p;
			cin >> a >> p;
			if (buffer.front() <= a) {
				start_time[i - 1] = a > buffer.back() ? a : buffer.back();
				buffer.pop();
				buffer.push((a > buffer.back() ? a : buffer.back()) + p);
			} else {
				start_time[i - 1] = -1;
			}
		}
		
		REP(i, 0, n - 1) {
			cout << start_time[i] << endl;
		}
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
