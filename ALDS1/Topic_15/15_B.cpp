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
typedef pair<double, double> pp;

int main(void) {
	int num, i;
	double W, v, w, ans = 0.0;
	cin >> num >> W;
	vector<pp> d(num);
	rep(i, num) {
		cin >> v >> w;
		d[i] = pp(v / w, w);
	}
	sort(d.begin(), d.end(), greater<pp>());
	rep(i, num) {
		ans += d[i].first * (min(W, d[i].second));
		W -= d[i].second;
		if (W <= 0.0)
			break;
	}
	printf("%.10lf\n", ans);
	return 0;
}