#include <iostream>
#include <vector>
#include <string>
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
} point;
typedef struct Point_Coordinates {
	double x, y;
} point;

point Rotate(point& a, double r) {
	// 点 a を原点中心に r 度回転させた変換先座標を返す
	point ans;
	r = PI * r / 180.0;
	ans.x = cos(r) * a.x - sin(r) * a.y;
	ans.y = sin(r) * a.x + cos(r) * a.y;
	return ans;
}

int main(void) {
	int num, i;
	double r, c, l, s, h;
	point a, b;
	cin >> a.x >> c >> r;
	a.y = 0;
	b = Rotate(a, r);
	r = PI * r / 180.0;
	h = c * sin(r);
	s = a.x * h / 2.0;
	b.x *= c / a.x;
	b.y *= c / a.x;
	b.x -= a.x;
	l = sqrt(b.x * b.x + b.y * b.y);
	l += a.x + c;
	printf("%.10lf\n", s);
	printf("%.10lf\n", l);
	printf("%.10lf\n", h);
	return 0;
}