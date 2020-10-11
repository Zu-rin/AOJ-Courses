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
	int num, i, j, k, a;
	cin >> num;
	vector<int> d(num + 1);
	vector<vector<int>> dp(num, vector<int>(num, INF));
	rep(i, num)
		cin >> d[i] >> a;
	d[i] = a;
	for (i = num - 1; i >= 0; i--) {
		dp[i][i] = 0;
		for (j = i + 1; j < num; j++) {
			for(k = i; k < j; k++)
				chmin(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i] * d[j + 1] * d[k + 1]);
		}
	}
	cout << dp[0][num - 1] << "\n";
	return 0;
}