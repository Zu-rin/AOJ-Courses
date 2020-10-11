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

void Dijkstra(int s, const vector<list<pp>> & e, vector<int> &ans) {
	int i;
	priority_queue<pp, vector<pp>, greater<pp>> que;
	ans[s] = 0;
	for (auto it = e[s].begin(); it != e[s].end(); it++)
		que.push((*it));
	while (!que.empty()) {
		auto a = que.top();
		que.pop();
		if (ans[a.second] == INF) {
			ans[a.second] = a.first;
			for (auto it = e[a.second].begin(); it != e[a.second].end(); it++)
				que.push(make_pair(a.first + (*it).first, (*it).second));
		}
	}
	return;
}

int main(void) {
	int num, i, E, s, a, b, c;
	cin >> num >> E >> s;
	vector<list<pp>> edge(num);
	vector<int> ans(num, INF);
	rep(i, E) {
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(c, b));
	}
	Dijkstra(s, edge, ans);
	rep(i, num) {
		if (ans[i] != INF)
			cout << ans[i] << "\n";
		else
			printf("INF\n");
	}
	return 0;
}