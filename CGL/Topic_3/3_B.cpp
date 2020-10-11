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
	ll x, y;
	friend Point_Coordinates operator-(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.x - r.x, l.y - r.y };
	}
} point;

int Cross(const point& a, const point& b) {
	return a.x * b.y - a.y * b.x;
}

int Judge(const point& a, const point& b, ll t) {
	return t * Cross(a, b) >= 0;
}

int main(void) {
	int num, i, ok = 1;
	ll t;
	cin >> num;
	vector<point> d(num);
	rep(i, num) {
		cin >> d[i].x >> d[i].y;
	}
	t = Cross(d[0] - d[num - 1], d[1] - d[0]) > 0 ? 1 : -1;
	for(i = 1; i < num; i++){
		if (!(ok = Judge(d[i] - d[i - 1], d[(i + 1) % num] - d[i], t)))
			break;
	}
	cout << ok << "\n";
	return 0;
}