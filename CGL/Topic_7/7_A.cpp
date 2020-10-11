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
	ll x, y, r;
} point;

int main(void) {
	int num, i;
	ll d, R, r;
	point a, b;
	cin >> a.x >> a.y >> a.r;
	cin >> b.x >> b.y >> b.r;
	d = (a.x - b.x) * (a.x - b.x);
	d += (a.y - b.y) * (a.y - b.y);
	R = (a.r + b.r) * (a.r + b.r);
	r = (a.r - b.r) * (a.r - b.r);
	if (d < r)
		printf("0\n");
	else if (d == r)
		printf("1\n");
	else if (d < R)
		printf("2\n");
	else if (d == R)
		printf("3\n");
	else
		printf("4\n");
	return 0;
}