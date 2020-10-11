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
	int num, i, j;
	string s, t;
	cin >> s >> t;
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, INF));
	rep(i, s.size() + 1)
		dp[i][0] = i;
	rep(i, t.size() + 1)
		dp[0][i] = i;
	for (i = 1; i <= s.size(); i++) {
		for (j = 1; j <= t.size(); j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			chmin(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
		}
	}
	cout << dp[s.size()][t.size()] << "\n";
	return 0;
}