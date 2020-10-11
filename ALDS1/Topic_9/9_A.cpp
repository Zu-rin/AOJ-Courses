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

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	rep(i, num) {
		printf("node %d: key = %d, ", i + 1, d[i]);
		if (i)
			printf("parent key = %d, ", d[(i - 1) >> 1]);
		if (2 * i + 1 < num)
			printf("left key = %d, ", d[2 * i + 1]);
		if (2 * i + 2 < num)
			printf("right key = %d, ", d[2 * i + 2]);
		printf("\n");
	}
	return 0;
}