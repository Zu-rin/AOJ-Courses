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

int Judge(int p, int k, vector<int> & d) {
	int i, a = 0, c = 1;
	rep(i, d.size()) {
		if (a + d[i] <= p)
			a += d[i];
		else {
			if (d[i] > p || c == k)
				return false;
			c++;
			a = d[i];
		}
	}
	return true;
}

int Search(int l, int r, int k, vector<int>& d) {
	if (l == r)
		return l;
	int p = (l + r) >> 1;
	if (Judge(p, k, d))
		return Search(l, p, k, d);
	else
		return Search(p + 1, r, k, d);
}

int main(void) {
	int num, i, k, ans, a, sum = 0;
	priority_queue<int, vector<int>, greater<int>> que;
	cin >> num >> k;
	vector<int> d(num);
	rep(i, num) {
		cin >> d[i];
		sum += d[i];
	}
	ans = Search(1, sum, k, d);
	cout << ans << "\n";
	return 0;
}