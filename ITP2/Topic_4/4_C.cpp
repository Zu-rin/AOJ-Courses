#include <iostream>
#include <vector>
#include <string>
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
	int num, q, i, j, b, e, t, buf;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	cin >> q;
	rep(j, q) {
		cin >> b >> e >> t;
		rep(i, e - b) {
			buf = d[b + i];
			d[b + i] = d[t + i];
			d[t + i] = buf;
		}
	}
	rep(i, num - 1)
		printf("%d ", d[i]);
	printf("%d\n", d[i]);
	return 0;
}