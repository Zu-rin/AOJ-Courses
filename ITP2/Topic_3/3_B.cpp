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

int IniSize(int num) {
	// 要素数 num が収まるセグ木のサイズを返す
	int n = 1;
	while (n <= num)
		n <<= 1;
	return (n << 1) - 1;
}

void Update_min(int pos, int n, vector<int> & d) {
	// 位置 pos(0-index) の値を n で更新する
	// セグ木のサイズは 2 * n - 1

	int i = pos + (d.size() >> 1);
	chmin(d[i], n);
	while (i > 0) {
		i = (i - 1) >> 1;
		chmin(d[i], n);
	}
	return;
}

void Update_max(int pos, int n, vector<int>& d) {
	// 位置 pos(0-index) の値を n で更新する
	// セグ木のサイズは 2 * n - 1

	int i = pos + (d.size() >> 1);
	chmax(d[i], n);
	while (i > 0) {
		i = (i - 1) >> 1;
		chmax(d[i], n);
	}
	return;
}

int Query_min(int pos, const range tag, range x, vector<int> & d) {
	// tag で指定した範囲に対して検索を行う
	// 外からの呼び出す時は Query(0, { a, b }, { 0, (segtreeの要素数 >> 1) + 1 }, d);
	// tag = [a, b)

	if (tag.r <= x.l || x.r <= tag.l)
		return INF;
	if (tag.l <= x.l && x.r <= tag.r)
		return d[pos];
	int a, b, ans;
	a = Query_min((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 }, d);
	b = Query_min((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r }, d);
	ans = min(a, b);
	return ans;
}

int Query_max(int pos, const range tag, range x, vector<int>& d) {
	// tag で指定した範囲に対して検索を行う
	// 外からの呼び出す時は Query(0, { a, b }, { 0, (num >> 1) + 1 }, d);
	// tag = [a, b)

	if (tag.r <= x.l || x.r <= tag.l)
		return -INF;
	if (tag.l <= x.l && x.r <= tag.r)
		return d[pos];
	int a, b, ans;
	a = Query_max((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 }, d);
	b = Query_max((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r }, d);
	ans = max(a, b);
	return ans;
}

int main(void) {
	int num, snum, i, d, q, l, r, ans;
	cin >> num;
	snum = IniSize(num);
	vector<int> mi(snum, INF), ma(snum, -INF);
	rep(i, num) {
		cin >> d;
		Update_min(i, d, mi);
		Update_max(i, d, ma);
	}
	cin >> q;
	rep(i, q) {
		cin >> d >> l >> r;
		if(d)
			ans = Query_max(0, { l, r }, { 0, (snum >> 1) + 1 }, ma);
		else
			ans = Query_min(0, { l, r }, { 0, (snum >> 1) + 1 }, mi);
		cout << ans << "\n";
	}
	return 0;
}