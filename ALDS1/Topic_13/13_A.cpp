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
typedef struct Point_Coordinates {
	int i, j;
} point;

void Record(const point& n, const int k, vector<vector<int>>& d) {
	int i, j;
	rep(i, 8) {
		d[i][n.j] += k;
		d[n.i][i] += k;
	}
	for (i = n.i, j = n.j; min(i, j) >= 0; i--, j--)
		d[i][j] += k;
	for (i = n.i, j = n.j; max(i, j) < 8; i++, j++)
		d[i][j] += k;
	for (i = n.i, j = n.j; i >= 0 && j < 8; i--, j++)
		d[i][j] += k;
	for (i = n.i, j = n.j; j >= 0 && i < 8; i++, j--)
		d[i][j] += k;
	d[n.i][n.j] -= 5 * k;
	return;
}

char Search(vector<vector<int>>& d, vector<char> &ans, int n = 0) {
	if (n == 8)
		return 1;
	if (ans[n])
		return Search(d, ans, n + 1);
	int i;
	rep(i, 8) {
		if (!d[n][i]) {
			Record({ n, i }, 1, d);
			if (Search(d, ans, n + 1)) {
				ans[n] = i + 1;
				return 1;
			}
			Record({ n, i }, -1, d);
		}
	}
	return 0;
}

int main(void) {
	int num, i, j;
	point n;
	vector<vector<int>> d(8, vector<int>(8, 0));
	vector<char> ans(8);
	cin >> num;
	rep(i, num) {
		cin >> n.i >> n.j;
		Record(n, 1, d);
		ans[n.i] = n.j + 1;
	}
	Search(d, ans);
	rep(i, 8) {
		rep(j, 8) {
			if (ans[i] - 1 == j)
				printf("Q");
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}