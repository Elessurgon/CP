// #include <bits/stdc++.h>

// using namespace std;

// #define REP(i,a,b) for (int i = a; i <= b; i++)
// #define REP_REV(i,a,b) for (int i = a; i >= b; i--)
// #define debug(x) cerr << #x << " is " << x << endl;
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) (int)(x).size()

// #define pb push_back
// #define rsz resize
// #define f first
// #define s second
// #define mp make_pair

// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vector<int>>;
// using vc = vector<char>;
// using ull = unsigned long long ;
// using pi = pair<int, int>;
// using vl = vector<long long>;
// using pl = pair<long long, long long>;
// using vpl = vector<pair<long long, long long>>;
// using msl = map<string, long long>;
// using vvl = vector<vector<long long>>;

// const ll MOD = 1e9 + 7;
// const int INF = int(1e9);

// ll gcd(ll a, ll b) {
// 	if (b == 0) return a;
// 	else return gcd(b, a % b);
// }

// ll lcm(ll a, ll b) {
// 	return (a * b) / gcd(a, b);
// }

// bool isPrime(int n) {
// 	if (n == 2) return true;
// 	for(int i = 2; i * i <= n; i++) {
// 		if (n % i == 0) return false;
// 	}
// 	return true;
// } 

// unsigned long long factorial(int n) {
//     const unsigned int M = MOD;
//     unsigned long long f = 1;
//     for (int i = 1; i <= n; i++)
//         f = (f*i) % M;  
//     return f;
// }

// ll binarySearch(ll num, vector<ll> a) {
// 	ll left = 0, right = sz(a) - 1;
// 	ll mid = (left + right) / 2;
// 	while(left <= right) {
// 		if (a[mid] == num) return mid;
// 		else if (a[mid] < num) left = mid + 1;
// 		else right = mid - 1;
// 		mid = (left + right) / 2;
// 	}
// 	return -1;
// }

// void solve() {
// }


// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	// freopen("split.in", "r", stdin);
// 	// freopen("split.out", "w", stdout);
// 	// ll t; cin >> t;
// 	// while (t--)
// 		solve();
// 	return 0;
// }
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define debug(x) cerr << #x << " is " << x << endl;

using namespace std;

using std::vector;
using std::swap;
using std::sort;

vector<int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int k = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
    if (a[i] == x) {
      k++;
      swap(a[i], a[k]);
    }
  }
  swap(a[l], a[j]);
  vector<int> indices = {j, k};
  return indices;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  // vector<int> m = partition3(a, l, r);
  // int m1 = m[0], m2 = m[1];

  // randomized_quick_sort(a, l, m1 - 1);
  // randomized_quick_sort(a, m2 + 1, r);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  // randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
