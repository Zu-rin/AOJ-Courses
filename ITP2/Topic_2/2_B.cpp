#include <iostream>
#include <vector>
#include <string>
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
	int n, num, i, q, k, x;
	cin >> n >> num;
	vector<queue<int>> d(n);
	rep(i, num) {
		cin >> q >> k;
		if (q == 0) {
			cin >> x;
			d[k].push(x);
		}
		else if (q == 1) {
			if (!d[k].empty())
				cout << d[k].front() << "\n";
		}
		else {
			if (!d[k].empty())
				d[k].pop();
		}
	}
	return 0;
}