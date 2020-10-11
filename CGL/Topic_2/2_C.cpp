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
#define INF 1e10

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
typedef struct Point_Coordinates {
	double x, y;
	friend Point_Coordinates operator-(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x - r.x, l.y - r.y };
	}
} point;

double Cross(const point& a, const point& b) {
	return a.x * b.y - a.y * b.x;
}

point Intersection(const point& a, const point& b, const point& c, const point& d) {
	double s, t, deno = Cross(b - a, d - c);
	point error = { INF, INF };
	if (deno == 0.0) {
		// ê¸ï™Ç™ïΩçs
		return error;
	}
	s = Cross(c - a, d - c) / deno;
	t = Cross(b - a, a - c) / deno;
	if (s < 0.0 || 1.0 < s || t < 0.0 || 1.0 < t) {
		// ê¸ï™Ç™åç∑ÇµÇƒÇ¢Ç»Ç¢
		return error;
	}
	return { a.x + s * (b - a).x, a.y + s * (b - a).y };
}

int main(void) {
	int num, i, j;
	point p[4];
	cin >> num;
	rep(j, num) {
		rep(i, 4)
			cin >> p[i].x >> p[i].y;
		point ans = Intersection(p[0], p[1], p[2], p[3]);
		if (ans.x == INF)
			printf("NULL\n");
		printf("%.10lf %.10lf\n", ans.x, ans.y);
	}
	return 0;
}