#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
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

//nCaÇåvéZÅAa < 0 ÇÃéû 0
ll Combi(ll n, ll a, vector<ll>& k) {
	a = min(a, n - a);
	if (a < 0)
		return 0;
	if (a == 0)
		return 1ll;
	ll ans = k[n] * Inverse(k[a]) % MOD;
	return ans * Inverse(k[n - a]) % MOD;
}

// d[n] = n! ÇÃîzóÒèâä˙âª
void Ini_fact(vector<ll>& d) {
	d[1] = 1;
	for (ll i = 2; i < d.size(); i++)
		d[i] = d[i - 1] * i % MOD;
	return;
}

int main(void) {
	ll num, k, i, j;
	cin >> num >> k;
	vector<ll> dp(k + 1, 0), kai(1001);
	Ini_fact(kai);
	dp[1] = k;
	for (i = 2; i <= k; i++) {
		ll a = Pow(i, num), w = -1;
		for (j = i - 1; j > 0; j--) {
			a += w * dp[j] * Combi(k, j, kai);
			a %= MOD;
			w *= -1;
		}
		dp[i] = Combi(k, i, kai) * a;
		dp[i] %= MOD;
	}
	if (dp[k] < 0)
		dp[k] += MOD;
	cout << dp[k] << "\n";
	return 0;
}