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
	int num, i, E, s, a, b, c, ans = 0;
	cin >> num >> E >> s;
	vector<list<pp>> edge(num);
	vector<int> ok(num, true);
	priority_queue<pp, vector<pp>, greater<pp>> que;
	ok[s] = 0;
	rep(i, E) {
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(c, b));
	}
	for (auto it = edge[s].begin(); it != edge[s].end(); it++)
		que.push(*it);
	while (!que.empty()) {
		auto e = que.top();
		que.pop();
		if (ok[e.second]) {
			ok[e.second] = 0;
			ans += e.first;
			for (auto it = edge[e.second].begin(); it != edge[e.second].end(); it++) {
				if(ok[(*it).second])
					que.push(*it);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}