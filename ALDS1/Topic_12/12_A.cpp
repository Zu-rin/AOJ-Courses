#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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

int Search(vector<vector<int>> & d) {
	int i, ans = 0;
	vector<char> ok(d.size(), 1);
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, 0));
	while (!que.empty()) {
		pp a = que.top();
		que.pop();
		if (ok[a.second]) {
			ans += a.first;
			ok[a.second] = 0;
			rep(i, d.size()) {
				if (ok[i] && d[a.second][i] >= 0)
					que.push(pp(d[a.second][i], i));
			}
		}
	}
	return ans;
}

int main(void) {
	int num, i, j;
	cin >> num;
	vector<vector<int>> d(num, vector<int>(num));
	rep(i, num) {
		rep(j, num) {
			cin >> d[i][j];
		}
	}
	cout << Search(d) << "\n";
	return 0;
}