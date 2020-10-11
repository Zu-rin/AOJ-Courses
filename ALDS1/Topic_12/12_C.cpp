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

void Dijk(vector<list<pp>>& d, vector<int>& ans) {
	int i;
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, 0));
	while (!que.empty()) {
		int c = que.top().first;
		int n = que.top().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			for (auto it = d[n].begin(); it != d[n].end(); it++) {
				if (ans[(*it).second] == INF)
					que.push(pp((*it).first + c, (*it).second));
			}
		}
	}
	return;
}

int main(void) {
	int num, i, j, n, a, b, c;
	cin >> num;
	vector<list<pp>> d(num);
	vector<int> ans(num, INF);
	rep(i, num) {
		cin >> a >> n;
		rep(j, n) {
			cin >> b >> c;
			d[a].push_back(pp(c, b));
		}
	}
	Dijk(d, ans);
	rep(i, num)
		printf("%d %d\n", i, ans[i]);
	return 0;
}