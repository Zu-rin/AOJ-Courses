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

typedef struct {
	int l, r;
} range;

class DelayedSegmentTree {
private:
	vector<ll> data, lazy, time;
	int size, t;

	int IniSize(int num) {
		// 要素数 num が収まるセグ木のサイズを返す
		int n = 1;
		while (n <= num)
			n <<= 1;
		return (n << 1) - 1;
	}

public:
	DelayedSegmentTree(int num, ll inidata) {
		t = 0;
		size = IniSize(num);
		data.resize(size);
		lazy.resize(size);
		time.resize(size);
		fill(data.begin(), data.end(), inidata);
		fill(lazy.begin(), lazy.end(), inidata);
		fill(time.begin(), time.end(), -1);
	}

	int Size() {
		return size;
	}

	ll Find(int pos) {
		// 位置 pos(0-index) の値を検索する

		return Find(0, pos, { 0, (size >> 1) + 1 });
	}

	ll Find(int pos, int tag, range x) {
		// 根から目標の葉へ向けて再帰的に lazy を伝播させる

		data[pos] += lazy[pos];

		if (x.l + 1 == x.r) {
			lazy[pos] = 0;
			return data[pos];
		}
		if (lazy[pos] > 0) {
			lazy[(pos << 1) + 1] += lazy[pos];
			lazy[(pos << 1) + 2] += lazy[pos];
			lazy[pos] = 0;
		}
		if (tag < ((x.l + x.r + 1) >> 1))
			return Find((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 });
		else
			return Find((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r });
	}

	void Update(const range tag, ll n) {
		// tag で指定した範囲に対して n で更新を行う
		// tag = [a, b)
		Update(0, tag, { 0, (size >> 1) + 1 }, n);
		t++;
		return;
	}

	void Update(int pos, const range tag, range x, ll n) {
		// tag で指定した範囲に対して検索を行う
		// 外からの呼び出す時は Query(0, { a, b }, { 0, (sg.Size() >> 1) + 1 });
		// tag = [a, b)

		if (tag.r <= x.l || x.r <= tag.l)
			return;
		if (tag.l <= x.l && x.r <= tag.r) {
			lazy[pos] += n;
			return;
		}
		Update((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 }, n);
		Update((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r }, n);
		return;
	}
};

int main(void) {
	int num, i, q, k, a, b;
	ll x;
	cin >> num >> q;
	DelayedSegmentTree sg(num, 0);
	rep(i, q) {
		cin >> k >> a;
		if (k) {
			cout << sg.Find(a - 1) <<"\n";
		}
		else {
			cin >> b >> x;
			sg.Update({ a - 1, b }, x);
		}
	}
	return 0;
}