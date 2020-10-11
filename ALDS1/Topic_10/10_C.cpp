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
	int num, i, j, k;
	string s, t;
	cin >> num;
	rep(k, num) {
		cin >> s >> t;
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
		rep(i, s.size()) {
			rep(j, t.size()) {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				if (s[i] == t[j])
					chmax(dp[i + 1][j + 1], dp[i][j] + 1);
				else
					chmax(dp[i + 1][j + 1], dp[i][j]);
			}
		}
		cout << dp[s.size()][t.size()] << "\n";
	}
	return 0;
}