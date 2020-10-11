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
	int num, i, j, a, b, k;
	cin >> num;
	vector<vector<int>> d(num + 1, vector<int>(num + 1, 0));
	rep(j, num) {
		cin >> a >> k;
		rep(i, k) {
			cin >> b;
			d[a][b] = 1;
		}
	}
	for (i = 1; i <= num; i++) {
		for (j = 1; j < num; j++)
			printf("%d ", d[i][j]);
		printf("%d\n", d[i][j]);
	}
	return 0;
}