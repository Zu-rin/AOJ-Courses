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
	int num, i, j, k, ans = 0;
	cin >> k >> num;
	vector<int> d(num), dp(k + 1, INF);
	rep(i, num)
		cin >> d[i];
	dp[0] = 0;
	rep(i, num) {
		rep(j, (int)dp.size() - d[i]) {
			chmin(dp[j + d[i]], dp[j] + 1);
		}
	}
	cout << dp[k] << "\n";
	return 0;
}