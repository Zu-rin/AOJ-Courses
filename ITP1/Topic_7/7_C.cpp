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
	int h, w, i, j;
	cin >> h >> w;
	vector<vector<int>> d(h + 1, vector<int>(w + 1, 0));
	rep(i, h) {
		rep(j, w)
			cin >> d[i][j];
		rep(j, w)
			d[i][w] += d[i][j];
	}
	rep(i, h) {
		rep(j, w + 1) {
			d[h][j] += d[i][j];
		}
	}
	rep(i, h + 1) {
		cout << d[i][0];
		for (j = 1; j <= w; j++)
			printf(" %d", d[i][j]);
		printf("\n");
	}
	return 0;
}