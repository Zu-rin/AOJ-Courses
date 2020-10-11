#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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
	double x, y;

	Point_Coordinates friend operator*(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x * r.x, l.y * r.y };
	}
	Point_Coordinates friend operator-(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x - r.x, l.y - r.y };
	}
	Point_Coordinates friend operator+(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x + r.x, l.y + r.y };
	}
	bool friend operator==(const Point_Coordinates& l, const Point_Coordinates& r) {
		return l.x == r.x && l.y == r.y;
	}
} point;

double Det(const point& a, const point& b) {
	return a.x * b.y - a.y * b.x;
}

double Scalar(const point& a) {
	point x = a * a;
	return sqrt(x.x + x.y);
}

point Rotate(point& a, double r) {
	// 点 a を原点中心に r 度回転させた変換先座標を返す
	point ans;
	r = PI * r / 180.0;
	ans.x = cos(r) * a.x - sin(r) * a.y;
	ans.y = sin(r) * a.x + cos(r) * a.y;
	return ans;
}

point Search(const point& a, const point& b, const point& p) {
	if (a == p)
		return p;
	point ab = b - a, ap = p - a;
	double xsin = Det(ab, ap) / Scalar(ab) / Scalar(ap);
	double dif = xsin * Scalar(ap) / Scalar(ab);
	point px = Rotate(ab, 270), k = { 2.0 * dif, 2.0 * dif };
	return px * k + p;
}

int main(void) {
	int num, i;
	point a, b, p, ans;
	cin >> a.x >> a.y >> b.x >> b.y >> num;
	rep(i, num) {
		cin >> p.x >> p.y;
		ans = Search(a, b, p);
		printf("%.10lf ", ans.x);
		printf("%.10lf\n", ans.y);
	}
	return 0;
}