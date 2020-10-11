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
	double x, y;

	Point_Coordinates friend operator-(const Point_Coordinates & l, const Point_Coordinates & r) {
		return { l.x - r.x, l.y - r.y };
	}
} point;

double Cross(const point & a, const point & b) {
	return a.x * b.y - a.y * b.x;
}

double Dot(const point& a, const point& b) {
	return a.x * b.x + a.y * b.y;
}

int main(void) {
	int num, i;
	double det, dot;
	point a, b, p, ab, ap;
	cin >> a.x >> a.y >> b.x >> b.y >> num;
	ab = b - a;
	rep(i, num) {
		cin >> p.x >> p.y;
		ap = p - a;
		det = Cross(ab, ap);
		if (det > 0)
			printf("COUNTER_CLOCKWISE\n");
		else if (det < 0)
			printf("CLOCKWISE\n");
		else {
			dot = Dot(ab, ap);
			if (dot < 0)
				printf("ONLINE_BACK\n");
			else {
				dot = Dot(ab, b - p);
				if (dot < 0)
					printf("ONLINE_FRONT\n");
				else
					printf("ON_SEGMENT\n");
			}
		}
	}
	return 0;
}