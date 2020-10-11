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

int main(void) {
	int num, k, i, j;
	cin >> num >> k;
	vector<vector<ll>> dp(num + 1, vector<ll>(k + 1, 0));
	dp[0][0] = 1;
	for (i = 1; i <= num; i++) {
		for (j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[max(0, i - j)][j];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[num][k] << "\n";
	return 0;
}