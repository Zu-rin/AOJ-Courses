#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Pow(ll n, ll k) {
	ll ans = 1, a = n % MOD;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ans;
}

ll Inverse(ll a) {
	return Pow(a, MOD - 2);
}

ll Combi(ll n, ll k) {
	chmin(k, n - k);
	if (k < 0)
		return 0;
	ll i, ans = 1;
	for (i = 1; i <= k; i++) {
		ans *= n--;
		ans %= MOD;
		ans *= Inverse(i);
		ans %= MOD;
	}
	return ans;
}

int main(void) {
	ll num, k, ans;
	cin >> num >> k;
	ans = Combi(k, num);
	while (num > 0) {
		ans *= num--;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}