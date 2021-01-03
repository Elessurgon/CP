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

vector<pair<int, int>> pts;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.s == p2.s) return p1.f < p2.f;
	return p1.s < p2.s;
}

int bruteForce(string s1, string s2) {
	int ans = 0;
	REP(i, 0, sz(s1) - 1) {
		REP(j, 0, sz(s2) - 1) {

		}
	}
	return ans;
}


void test() {
	return;
	// while(true) {
	// 	int min = -1e9, max = 1e9; 
	// 	int n = 2 + (rand() % 100);
	// 	pts.clear();
	// 	REP(i, 0, n - 1) {
	// 		int x = (rand() % (max - min)) + min, y = (rand() % (max - min)) + min;
	// 		pts.pb({x, y});
	// 	}
	// 	sort(all(pts));
	// 	double ans = minimumDistance(0, sz(pts) - 1);
	// 	double testing = bruteForce();
	// 	cout << endl;
	// 	cout << setprecision(9) << sqrt(ans);
	// 	cout << endl;
	// 	cout << setprecision(9) << sqrt(testing);	
	// 	double epi = 1e-3;
	// 	if (abs(ans - testing) > epi) {
	// 		cout << endl;
	// 		debug(sz(pts));
	// 		REP(i, 0, sz(pts) - 1) {
	// 			cout << pts[i].f << " " << pts[i].s << endl;
	// 		}
	// 		cout << endl << testing << endl << ans;
	// 		break;
	// 	}
	// }
}

void solve() {
	int n, m;
	cin >> n;
	vi a(n);
	REP(i, 0, n - 1) {
		cin >> a[i];
	}
	cin >> m;
	vi b(m);
	REP(i, 0, m - 1) {
		cin >> b[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	REP(i, 1, n) {
		REP(j, 1, m) {
			int mismatch = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] =  dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = mismatch;
			}
		}
	}
	// REP(i, 0, n) {
	// 	REP(j, 0, m) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[n][m] << endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("split.in", "r", stdin);
	// freopen("split.out", "w", stdout);
	// ll t; cin >> t;
	// while (t--)
		solve();
		// test();
	return 0;
}
