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

class UnionFind {
private:
	vector<int> p;

public:
	UnionFind(int num) {
		p.resize(num + 1);
		int i;
		rep(i, p.size())
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
	int num, i, q, j, k, a, b;
	cin >> num >> q;
	UnionFind p(num);
	rep(j, q) {
		cin >> k >> a >> b;
		if (k)
			printf("%d\n", p.Same(a, b));
		else
			p.Union(a, b);
	}
	return 0;
}