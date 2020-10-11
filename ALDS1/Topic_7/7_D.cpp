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

typedef struct {
	int par, left, right;
	ll L, R;
} node;

class Tree {
public:
	vector<node> d;
	int root;

	Tree(int num) {
		int i;
		d.resize(num);
		rep(i, num)
			d[i].par = d[i].left = d[i].right = d[i].L = -1;
		root = 0;
	}

	int Add(const int tag, int n, ll v, vector<ll> &lv) {
		if (n >= 0) {
			ll a = 1ll << tag;
			if (d[n].L & a)
				d[n].left = Add(tag, d[n].left, d[n].L, lv);
			else
				d[n].right = Add(tag, d[n].right, d[n].R, lv);
			return n;
		}
		v -= 1ll << n;
		if (v == 0) {
			d[tag].left = d[tag].right = 0;
			d[tag].L = d[tag].R = 0;
		}
		else {
			d[tag].L = lv[tag] & v;
			d[tag].R = v - d[tag].L;
		}
		return tag;
	}

	void Search(int n) {
		if (d[n].left >= 0) {
			Search(d[n].left);
			printf(" ");
		}
		if (d[n].right >= 0) {
			Search(d[n].right);
			printf(" ");
		}
		cout << n + 1;
	}
};

int main(void) {
	int num, i, n;
	ll v = 0, all;
	cin >> num;
	Tree tr(num);
	vector<int> a(num);
	vector<ll> lv(num), d(num);
	rep(i, num) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, num) {
		cin >> n;
		n--;
		lv[n] = v;
		v |= 1ll << n;
	}
	all = (1ll << num) - 1;
	tr.root = a[0];
	tr.Add(a[0], -1, all, lv);
	for(i = 1; i < num; i++) {
		tr.Add(a[i], a[0], all, lv);
	}
	tr.Search(a[0]);
	printf("\n");
	return 0;
}