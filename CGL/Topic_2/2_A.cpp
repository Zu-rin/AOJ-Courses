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
	ll x, y;

	friend Point_Coordinates operator-(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x - r.x, l.y - r.y };
	}

} point;

ll Length(point& a) {
	return a.x * a.x + a.y * a.y;
}

ll Cross(point & a, point & b) {
	return a.x * b.y - a.y * b.x;
}

point MakeVector() {
	point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	return b - a;
}

int main(void) {
	ll num, i, c;
	point a, b;
	cin >> num;
	rep(i, num) {
		a = MakeVector();
		b = MakeVector();
		c = abs(Cross(a, b));
		if (c) {
			if (c * c == Length(a) * Length(b))
				printf("1\n");
			else
				printf("0\n");
		}
		else
			printf("2\n");
	}
	return 0;
}