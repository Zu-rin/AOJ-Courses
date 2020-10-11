#include <iostream>
#include <vector>
#include <string>
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

class WeightedUnionFind {
private:
	vector<int> p, w;

public:
	WeightedUnionFind(int num) {
		p.resize(num + 1);
		w.resize(num + 1);
		for (int i = 0; i < p.size(); i++)
			p[i] = i;
	}

	int Root(int n) {
		if (p[n] == n)
			return n;
		int rn = Root(p[n]);
		w[n] += w[p[n]];
		return p[n] = rn;
	}

	void Union(int a, int b, int weight) {
		int ra = Root(a);
		int rb = Root(b);
		p[rb] = ra;
		w[rb] = weight + w[a] - w[b];
		return;
	}

	int Same(int a, int b) {
		a = Root(a);
		b = Root(b);
		return a == b;
	}

	int DiffWeight(int a, int b) {
		if (Same(a, b))
			return w[b] - w[a];
		else
			return INF;
	}
};

int main(void) {
	int num, i, j, q, a, b, w, k, ans;
	cin >> num >> q;
	WeightedUnionFind p(num);
	rep(j, q) {
		cin >> k >> a >> b;
		if (k) {
			ans = p.DiffWeight(a, b);
			if (ans == INF)
				printf("?\n");
			else
				cout << ans << "\n";
		}
		else {
			cin >> w;
			p.Union(a, b, w);
		}
	}
	return 0;
}