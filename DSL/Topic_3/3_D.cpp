#include <iostream>
#include <vector>
#include <string>
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

typedef struct {
	int l, r;
} range;

class SegmentTree {
private:
	vector<ll> d;
	int size;

public:
	SegmentTree(int num, ll inidata) {
		size = IniSize(num);
		d.resize(size);
		fill(d.begin(), d.end(), inidata);
	}

	int IniSize(int num) {
		// 要素数 num が収まるセグ木のサイズを返す
		int n = 1;
		while (n < num)
			n <<= 1;
		return (n << 1) - 1;
	}

	int Size() {
		return size;
	}

	void Update(int pos, int n) {
		// 位置 pos(0-index) の値を n で更新する

		int i = pos + (d.size() >> 1);
		d[i] = n;
		while (i > 0) {
			i = (i - 1) >> 1;
			d[i] = min(d[(i << 1) + 1], d[(i << 1) + 2]);
		}
		return;
	}

	ll Query(const range tag) {
		// tag で指定した範囲に対して検索を行う
		// tag = [a, b)
		return Query(0, tag, { 0, (Size() >> 1) + 1 });
	}

	ll Query(int pos, const range tag, range x) {
		// tag で指定した範囲に対して検索を行う
		// tag = [a, b)

		if (tag.r <= x.l || x.r <= tag.l)
			return INF; // ***注意***
		if (tag.l <= x.l && x.r <= tag.r)
			return d[pos];
		ll a, b, ans;
		a = Query((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 });
		b = Query((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r });
		ans = min(a, b);
		return ans;
	}
};

int main(void) {
	int num, i, l, a;
	cin >> num >> l;
	SegmentTree sg(num, INF);
	rep(i, num) {
		cin >> a;
		sg.Update(i, a);
	}
	rep(i, num - l) {
		cout << sg.Query({ i, i + l }) << " ";
	}
	cout << sg.Query({ i, i + l }) << "\n";
	return 0;
}