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
	int num, i, j, d[4][3][10] = { 0 }, a, b, c, k;
	string s = "####################\n";
	cin >> num;
	rep(i, num) {
		cin >> a >> b >> c >> k;
		d[a - 1][b - 1][c - 1] += k;
	}
	rep(i, 4) {
		if (i > 0)
			cout << s;
		rep(j, 3) {
			rep(k, 10) {
				cout << " " << d[i][j][k];
			}
			printf("\n");
		}
	}
	return 0;
}