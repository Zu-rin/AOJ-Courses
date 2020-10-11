#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF (1ll << 31) - 1

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

typedef struct {
	int l, r;
} range;

class SegmentTree {
private:
	vector<int> d;
	int size;

	ll Query(int pos, const range tag, range x) {
		// tag で指定した範囲に対して検索を行う
		// 外からの呼び出す時は Query(0, { a, b }, { 0, (sg.Size() >> 1) + 1 });
		// tag = [a, b)

		if (tag.r <= x.l || x.r <= tag.l)
			return INF;
		if (tag.l <= x.l && x.r <= tag.r)
			return d[pos];
		ll a, b, ans;
		a = Query((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 });
		b = Query((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r });
		ans = min(a, b);
		return ans;
	}

public:
	SegmentTree(int num, ll inidata) {
		size = IniSize(num);
		d.resize(size);
		fill(d.begin(), d.end(), inidata);
	}

	int IniSize(int num) {
		// 要素数 num が収まるセグ木のサイズを返す
		int n = 1;
		while (n <= num)
			n <<= 1;
		return (n << 1) - 1;
	}

	int Size() {
		return size;
	}

	void Update(int pos, int n) {
		// 位置 pos(0-index) の値を n で更新する
		// セグ木のサイズは 2^n - 1

		int i = pos + (d.size() >> 1);
		d[i] = n;
		while (i > 0) {
			i = (i - 1) >> 1;
			d[i] = min(d[(i << 1) + 1], d[(i << 1) + 2]);
		}
		return;
	}

	ll Query(int pos, const range tag) {
		// tag で指定した範囲に対して検索を行う
		// tag = [a, b)
		return Query(pos, tag, { 0, (Size() >> 1) + 1 });
	}
};

int main(void) {
	int num, i, q, k, a, b, s;
	cin >> num >> q;
	SegmentTree sg(num, INF);
	rep(i, q) {
		cin >> k >> a >> b;
		if (k) {
			cout << sg.Query(0, { a, b + 1 }) << "\n";
		}
		else {
			sg.Update(a, b);
		}
	}
	return 0;
}