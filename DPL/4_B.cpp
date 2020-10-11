#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;

int main(void) {
	int num, i, j, k;
	ll l, r, a, ans = 0;
	cin >> num >> k >> l >> r;
	vector<map<ll, ll>> dp(k + 1);
	dp[0][0] = 1;
	rep(i, num) {
		cin >> a;
		for(j = k - 1; j >= 0; j--) {
			for (auto it = dp[j].begin(); it != dp[j].end(); it++) {
				if ((*it).first + a <= r)
					dp[j + 1][(*it).first + a] += dp[j][((*it).first)];
			}
		}
	}
	for (auto it = dp[k].begin(); it != dp[k].end(); it++) {
		if ((*it).first >= l) {
			ans += (*it).second;
		}
	}
	cout << ans << "\n";
	return 0;
}