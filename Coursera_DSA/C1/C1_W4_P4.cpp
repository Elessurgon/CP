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

int inversions = 0;

void merge(vector<int>& a, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  vi l(n1), r(n2);
  REP(i, 0, n1 - 1) {
    l[i] = a[left + i];
  }
  REP(i, 0, n2 - 1) {
    r[i] = a[mid + i];
  }

  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2) {
    if (l[i] <= r[j]) {
      a[k] = l[i];
      i++;
    } else {
      inversions += mid - left - i; 
      a[k] = r[j];
      j++;
    }
    k++;
  }

  if (i == n1) {
    while(j < n2) {
      a[k] = r[j];
      j++;
      k++;
    }
  } else {
    while(i < n1) {
      a[k] = l[i];
      i++;
      k++;
    }
  }
}

void mergesort(vector<int>& a, int left, int right) {
  if (left + 1 >= right) {
    return;
  }
  mergesort(a, left, (left + right) / 2);
  mergesort(a, (left + right) / 2, right);
  merge(a, left, (left + right) / 2, right); 
}

int invs(vector<int> a) {
  int inv = 0;
  REP(i, 0, sz(a) - 1) {
    REP(j, i + 1, sz(a) - 1) {
      if (a[i] > a[j]) {
        inv++;
      }
    }
  }
  return inv;
}

void solve() {
  int n; cin >> n;
  vi a(n);
  REP(i, 0, n - 1) {
    cin >> a[i];
  }
  mergesort(a, 0, n);
  cout << inversions << endl;
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
