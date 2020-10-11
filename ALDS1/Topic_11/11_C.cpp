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

void BFS(vector<list<int>> & d, vector<int> & ans) {
	int i, n;
	queue<int> que;
	ans[1] = 0;
	que.push(1);
	while (!que.empty()) {
		n = que.front();
		que.pop();
		for (auto it = d[n].begin(); it != d[n].end(); it++) {
			if (ans[*it] == -1) {
				ans[*it] = ans[n] + 1;
				que.push(*it);
			}
		}
	}
	return;
}

int main(void) {
	int num, i, j, k, a, b;
	cin >> num;
	vector<list<int>> d(num + 1);
	vector<int> ans(num + 1, -1);
	rep(j, num) {
		cin >> a >> k;
		rep(i, k) {
			cin >> b;
			d[a].push_back(b);
		}
	}
	BFS(d, ans);
	for (i = 1; i <= num; i++)
		printf("%d %d\n", i, ans[i]);
	return 0;
}