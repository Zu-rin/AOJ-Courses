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
	int num, q, i, j, a;
	cin >> num;
	vector<vector<int>> dp(num + 1, vector<int>(40001, 0));
	dp[0][0] = true;
	rep(i, num) {
		cin >> a;
		rep(j, dp[i].size()) {
			if (dp[i][j])
				dp[i + 1][j] = dp[i + 1][j + a] = true;
		}
	}
	cin >> q;
	rep(i, q) {
		cin >> a;
		if (dp[num][a])
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}