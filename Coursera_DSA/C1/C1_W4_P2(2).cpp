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

#include <algorithm>
#include <iostream>
#include <vector>
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  // cout << "PRE: \n";	
  // debug(left)
  // debug(right)
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  // cout << "LEFT" << endl;
  int max1 = get_majority_element(a, left, (left + right - 1) / 2 + 1);
  // cout << "RIGHT" << endl;
  int max2 = get_majority_element(a, (left + right - 1) / 2 + 1, right);
  // cout << "POST: \n";
  // debug(left)
  // debug(right)
  // debug(max1)
  // debug(max2)
  // for(int i = left; i < right; i++) {
  // 	cout << a[i] << " ";
  // }
  // cout << endl;
  int lcount = 0;
  for(int i = left; i < right; i++) {
  	if(a[i] == max1) lcount++;
  }
  if (lcount > (right - left) / 2) return max1;
  int rcount = 0;
  for(int i = left; i < right; i++) {
  	if(a[i] == max2) rcount++;
  }
  if (rcount > (right - left) / 2) return max2;
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}