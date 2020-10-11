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
	int x, y;
	friend Point_Coordinates operator-(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x - r.x, l.y - r.y };
	}
} point;

int Dot(const point& a, const point& b) {
	return a.x * b.x + a.y * b.y;
}
int Dot(const point& a) {
	return Dot(a, a);
}

int Direc(const point& a, const point& b) {
	int c = a.x * b.y - a.y * b.x;
	if (c == 0)
		return 0;
	return c > 0 ? 1 : -1;
}

int Is_online(const point& v, const point& a) {
	if (Dot(v, a) >= 0 && Dot(v) >= Dot(a))
		return 1;
	return 0;
}

int Judge(const point& a, const point& b, const point& c, const point& d) {
	int x, y;
	point s = b - a, t;
	x = Direc(s, c - a);
	y = Direc(s, d - a);
	if (x == 0 && Is_online(s, c - a))
		return 1;
	if (y == 0 && Is_online(s, d - a))
		return 1;
	if (x == 0 && y == 0 && Dot(c - a, d - a) < 0)
		return 1;
	if (x * y < 0)
		return 0;
	return -1;
}

int main(void) {
	int num, i, j, a;
	point p[4];
	cin >> num;
	rep(j, num) {
		rep(i, 4) {
			cin >> p[i].x >> p[i].y;
		}
		a = Judge(p[0], p[1], p[2], p[3]);
		if (a) {
			if (a < 0)
				printf("0\n");
			else
				printf("1\n");
			continue;
		}
		a = Judge(p[2], p[3], p[0], p[1]);
		if (a < 0)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}