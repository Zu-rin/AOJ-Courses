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
} point;

ll Area(const point& a, const point& b) {
	return (a.x - b.x) * (a.y + b.y);
}

int main(void) {
	int num, i;
	cin >> num;
	vector<point> d(num);
	rep(i, num)
		cin >> d[i].x >> d[i].y;
	ll sum = Area(d[num - 1], d[0]);
	rep(i, num - 1) {
		sum += Area(d[i], d[i + 1]);
	}
	sum = abs(sum);
	cout << (sum >> 1);
	if (sum & 1)
		printf(".5");
	else
		printf(".0");
	printf("\n");
	return 0;
}