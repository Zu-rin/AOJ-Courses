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
	int num, i, q, a, d;
	deque<int> que;
	cin >> num;
	rep(i, num) {
		cin >> q >> a;
		if (q == 0) {
			cin >> d;
			if (a)
				que.push_back(d);
			else
				que.push_front(d);
		}
		else if (q == 1) {
			cout << que[a] << "\n";
		}
		else {
			if (a)
				que.pop_back();
			else
				que.pop_front();
		}
	}
	return 0;
}