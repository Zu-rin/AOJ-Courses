#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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
		// �v�f�� num �����܂�Z�O�؂̃T�C�Y��Ԃ�
		int n = 1;
		while (n < num)
			n <<= 1;
		return (n << 1) - 1;
	}

	int Size() {
		return size;
	}

	void Update(int pos) {
		// �ʒu pos(0-index) �̒l�� n �ōX�V����

		int i = pos + (d.size() >> 1);
		d[i]++;
		while (i > 0) {
			i = (i - 1) >> 1;
			d[i]++;
		}
		return;
	}

	ll Query(const range tag) {
		// tag �Ŏw�肵���͈͂ɑ΂��Č������s��
		// tag = [a, b)
		return Query(0, tag, { 0, (Size() >> 1) + 1 });
	}

	ll Query(int pos, const range tag, range x) {

		if (tag.r <= x.l || x.r <= tag.l)
			return 0; // ***����***
		if (tag.l <= x.l && x.r <= tag.r)
			return d[pos];
		ll a, b, ans;
		a = Query((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 });
		b = Query((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r });
		ans = a + b;
		return ans;
	}
};

int main(void) {
	int num, i, a;
	ll ans = 0;
	cin >> num;
	vector<int> d(num);
	map<int, int> mp;
	SegmentTree st(num, 0);
	rep(i, num) {
		cin >> d[i];
		mp[d[i]];
	}
	i = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		(*it).second = i++;
	}
	rep(i, num) {
		a = mp[d[i]];
		ans += st.Query({ a,num });
		st.Update(a);
	}
	cout << ans << "\n";
	return 0;
}