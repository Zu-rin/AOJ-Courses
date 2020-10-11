#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
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

int Size(int num) {
	int ans = 0;
	while (num > 0) {
		if (num & 1)
			ans++;
		num >>= 1;
	}
	return ans;
}

int Search(int s, vector<vector<int>> &x, vector<int> &dp) {
	if (dp[s] != INF)
		return dp[s];
	int i, j;
	rep(i, x.size()) {
		if (s & (1 << i))
			continue;
		for (j = i + 1; j < x.size(); j++) {
			if (!(s & (1 << j)))
				chmin(dp[s], x[i][j] + Search(s | (1 << i) | (1 << j), x, dp));
		}
	}
	return dp[s];
}

int main(void) {
	int num, i, E, j, k, a, b, v = 0, s;
	ll c, ans = 0;
	cin >> num >> E;
	vector<vector<ll>> d(num, vector<ll>(num, INF));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
	rep(i, E) {
		cin >> a >> b >> c;
		ans += c;
		d[b][a] = chmin(d[a][b], c);
		v ^= 1 << a;
		v ^= 1 << b;
	}
	rep(k, num) {
		rep(i, num) {
			rep(j, num) {
				chmin(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	s = Size(v);
	vector<vector<int>> x(s, vector<int>(s));
	vector<int> dp(1 << s, INF);
	a = 0;
	rep(i, num) {
		if (!(v & (1 << i)))
			continue;
		b = 0;
		rep(j, num) {
			if (v & (1 << j)) {
				x[a][b] = x[b][a] = d[i][j];
				b++;
			}
		}
		a++;
	}
	dp[dp.size() - 1] = 0;
	ans += Search(0, x, dp);
	cout << ans << "\n";
	return 0;
}