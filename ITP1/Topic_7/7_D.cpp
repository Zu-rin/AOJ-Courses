#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, k, a, b, c;
	cin >> a >> b >> c;
	vector<vector<ll>> x(a, vector<ll>(b)), y(b, vector<ll>(c)), ans(a, vector<ll>(c, 0));
	rep(i, a) {
		rep(j, b)
			cin >> x[i][j];
	}
	rep(i, b) {
		rep(j, c)
			cin >> y[i][j];
	}
	rep(i, a) {
		rep(j, c) {
			rep(k, b) {
				ans[i][j] += x[i][k] * y[k][j];
			}
		}
	}
	rep(i, a) {
		cout << ans[i][0];
		for (j = 1; j < c; j++)
			printf(" %lld", ans[i][j]);
		printf("\n");
	}
	return 0;
}