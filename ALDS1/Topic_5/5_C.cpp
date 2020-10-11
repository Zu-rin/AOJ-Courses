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
typedef struct {
	double x, y;
} point;

point Comp(point a, point b) {
	return { a.x + b.x, a.y + b.y };
}

point Rotate(point & a, double r) {
	// 原点中心に点 a を r 度回転させた変換先座標を返す
	point ans;
	r = PI * r / 180.0;
	ans.x = cos(r) * a.x - sin(r) * a.y;
	ans.y = sin(r) * a.x + cos(r) * a.y;
	return ans;
}

point Square(point a, point b) {
	point ab = { b.x - a.x, b.y - a.y };
	return Comp(a, Rotate(ab, 60));
}

void Print(point a) {
	printf("%.10lf %.10lf\n", a.x, a.y);
	return;
}

int Lim;
void Koch(int n, point l, point r) {
	point a, b, c, lr = { r.x - l.x, r.y - l.y };
	a = { l.x + lr.x / 3.0, l.y + lr.y / 3.0 };
	b = { l.x + lr.x * 2.0 / 3.0, l.y + lr.y * 2.0 / 3.0 };
	c = Square(a, b);
	if (n == Lim) {
		Print(a);
		Print(c);
		Print(b);
		Print(r);
	}
	else {
		Koch(n + 1, l, a);
		Koch(n + 1, a, c);
		Koch(n + 1, c, b);
		Koch(n + 1, b, r);
	}
	return;
}

int main(void) {
	int num, i;
	point a = { 0, 0 }, b = { 100.0, 0 };
	cin >> Lim;
	Print(a);
	if (Lim == 0)
		Print(b);
	else
		Koch(1, a, b);
	return 0;
}