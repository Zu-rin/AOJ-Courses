#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 28

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Search(int s, int n, const vector<vector<int>> & e, vector<vector<int>> &dp) {
	if (dp[s][n] >= 0)
		return dp[s][n];
	if (s == (1 << e.size()) - 1)
		return dp[s][n] = e[n][0];
	int i, cost = INF;
	rep(i, e.size()) {
		if (!(s & (1 << i))) {
			chmin(cost, Search(s | (1 << i), i, e, dp) + e[n][i]);
		}
	}
	return dp[s][n] = cost;
}

int main(void) {
	int num, i, E, a, b, c, ans;
	cin >> num >> E;
	vector<vector<int>> e(num, vector<int>(num, INF)), dp(1 << num, vector<int>(num, -1));
	rep(i, num)
		e[i][i] = 0;
	rep(i, E) {
		cin >> a >> b >> c;
		e[a][b] = c;
	}
	ans = Search(1, 0, e, dp);
	if (ans >= INF)
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}