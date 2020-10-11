#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
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
typedef tuple<int, int, int> tp;

class UnionFind {
private:
	vector<int> p;

public:
	UnionFind(int num) {
		p.resize(num + 1);
		for (int i = 0; i < p.size(); i++)
			p[i] = i;
	}

	int Parent(int n) {
		if (p[n] == n)
			return n;
		return p[n] = Parent(p[n]);
	}

	void Union(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		p[a] = b;
		return;
	}

	int Same(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		return a == b;
	}
};

int main(void) {
	int num, i, E, ans = 0, a, b, c;
	cin >> num >> E;
	vector<tp> edge(E);
	UnionFind p(num);
	rep(i, E) {
		cin >> a >> b >> c;
		edge[i] = make_tuple(c, a, b);
	}
	sort(edge.begin(), edge.end());
	rep(i, E) {
		auto e = edge[i];
		if (!p.Same(get<1>(e), get<2>(e))) {
			p.Union(get<1>(e), get<2>(e));
			ans += get<0>(e);
		}
	}
	cout << ans << "\n";
	return 0;
}