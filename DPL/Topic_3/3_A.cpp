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
typedef struct Point_Coordinates {
	int i, j;
} point;

int Search(point s, const vector<vector<int>>& d) {
	int i, ans = 0, n;
	point e;
	for (i = 1; s.i + i < d.size() && s.j + i < d[0].size();) {
		e = {s.i + i, s.j + i};
		n = d[e.i][e.j] + d[s.i][s.j] - d[s.i][e.j] - d[e.i][s.j];
		if (n)
			s = { s.i + 1, s.j + 1 };
		else {
			chmax(ans, i);
			i++;
		}
	}
	return ans;
}

int main(void) {
	int num, i, j, h, w, ans = 0;
	cin >> h >> w;
	vector<vector<int>> d(h + 1, vector<int>(w + 1, 0));
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++)
			cin >> d[i][j];
		rep(j, w)
			d[i][j + 1] += d[i][j];
	}
	for (j = 1; j <= w; j++) {
		rep(i, h)
			d[i + 1][j] += d[i][j];
	}
	rep(i, h)
		chmax(ans, Search({ i, 0 }, d));
	for (i = 1; i < w; i++)
		chmax(ans, Search({ 0, i }, d));
	cout << ans * ans << "\n";
	return 0;
}