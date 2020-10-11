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

int main(void) {
	int num, i, j, W;
	cin >> num >> W;
	vector<vector<int>> dp(num + 1, vector<int>(W + 1, 0));
	vector<int> v(num), w(num);
	rep(i, num)
		cin >> v[i] >> w[i];
	rep(i, num) {
		rep(j, W + 1)
			dp[i + 1][j] = dp[i][j];
		rep(j, W + 1 - w[i])
			chmax(dp[i + 1][j + w[i]], dp[i][j] + v[i]);

	}
	cout << dp[num][W] << "\n";
	return 0;
}