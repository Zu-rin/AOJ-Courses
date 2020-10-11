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

int DFS(vector<list<int>> & d, vector<int> & s, vector<int> & e, int n, int t) {
	if (s[n])
		return t;
	s[n] = t++;
	for (auto it = d[n].begin(); it != d[n].end(); it++)
		t = DFS(d, s, e, *it, t);
	e[n] = t++;
	return t;
}

int main(void) {
	int num, i, j, k, a, b, t = 1;
	cin >> num;
	vector<list<int>> d(num + 1);
	vector<int> s(num + 1), e(num + 1);
	rep(j, num) {
		cin >> a >> k;
		rep(i, k) {
			cin >> b;
			d[a].push_back(b);
		}
	}
	for (i = 1; i <= num; i++)
		t = DFS(d, s, e, i, t);
	for (i = 1; i <= num; i++)
		printf("%d %d %d\n", i, s[i], e[i]);
	return 0;
}