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
typedef pair<string, int> pp;

int main(void) {
	int num, i, k, a, t = 0;
	string s;
	cin >> num >> k;
	queue<pp> que;
	rep(i, num) {
		cin >> s >> a;
		que.push(make_pair(s, a));
	}
	while (!que.empty()) {
		pp d = que.front();
		que.pop();
		if (d.second > k) {
			t += k;
			d.second -= k;
			que.push(d);
		}
		else {
			t += d.second;
			cout << d.first << " " << t << "\n";
		}
	}
	return 0;
}