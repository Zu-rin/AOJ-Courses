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
	int num, i, w, h, x, y, r, ok = true;
	cin >> w >> h >> x >> y >> r;
	vector<int> X(4, x), Y(4, y);
	X[0] -= r;
	Y[2] -= r;
	X[1] += r;
	Y[3] += r;
	rep(i, 4) {
		if (min(X[i], Y[i]) < 0 || X[i] > w || Y[i] > h) {
			ok = 0;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}