#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
typedef struct {
	double x, y;
} point;

int main(void) {
	int num, i;
	double ans;
	point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	a.x -= b.x;
	a.y -= b.y;
	ans = a.x * a.x + a.y * a.y;
	ans = sqrt(ans);
	printf("%.10lf\n", ans);
	return 0;
}