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
	int num, i, q, j, l, r, k;
	cin >> num;
	vector<vector<int>> d(1001, vector<int>(num, -1));
	rep(i, num)
		cin >> d[0][i];
	cin >> q;
	rep(i, q) {
		cin >> l >> k >> r;
		k = r - k;
		rep(j, l)
			d[i + 1][j] = d[i][j];
		rep(j, r - l)
			d[i + 1][l + ((j + k) % (r - l))] = d[i][l + j];
		for (j = r; j < num; j++)
			d[i + 1][j] = d[i][j];
	}
	rep(i, num - 1)
		printf("%d ", d[q][i]);
	printf("%d\n", d[q][i]);
	return 0;
}