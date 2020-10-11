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
	int num, i, j, a, b, c, d, ans = 0;
	cin >> num;
	vector<vector<int>> mp(1002, vector<int>(1002, 0));
	rep(i, num) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		mp[a][b]++;
		mp[a][d]--;
		mp[c][b]--;
		mp[c][d]++;
	}
	rep(i, mp.size()) {
		rep(j, mp.size() - 1) {
			mp[i][j + 1] += mp[i][j];
		}
	}
	rep(j, mp.size()) {
		rep(i, mp.size() - 1) {
			mp[i + 1][j] += mp[i][j];
		}
	}
	rep(i, mp.size()) {
		rep(j, mp.size()) {
			chmax(ans, mp[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}