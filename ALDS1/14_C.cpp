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
typedef unsigned long long ull;
typedef pair<int, int> pp;
typedef struct Hashpair {
	ull x, y;
	Hashpair() {
		x = y = 0;
	}
	Hashpair(ull X, ull Y) {
		x = X;
		y = Y;
	}
	Hashpair& operator+=(const Hashpair& r) {
		this->x += r.x;
		this->y += r.y;
		return *this;
	}
	Hashpair& operator-=(const Hashpair& r) {
		this->x -= r.x;
		this->y -= r.y;
		return *this;
	}
	Hashpair& operator*=(const Hashpair& r) {
		this->x *= r.x;
		this->y *= r.y;
		return *this;
	}
	friend Hashpair operator+(Hashpair l, const Hashpair& r) {
		l += r;
		return l;
	}
	friend Hashpair operator-(Hashpair l, const Hashpair& r) {
		l -= r;
		return l;
	}
	friend Hashpair operator*(Hashpair l, const Hashpair& r) {
		l *= r;
		return l;
	}
	friend bool operator==(const Hashpair& l, const Hashpair& r) {
		return l.x == r.x && l.y == r.y;
	}
} hashp;

ull Power(ull n, int k) {
	ull ans = 1, a = n;
	while (k > 0) {
		if (k & 1)
			ans *= a;
		a *= a;
		k >>= 1;
	}
	return ans;
}

ull k = 311, l = 317;

void Input(vector<vector<ull>>& d) {
	int h, w, i, j;
	string s;
	cin >> h >> w;
	d.resize(h + 1);
	d[0].resize(w + 1);
	for(i = 1; i <= h; i++) {
		d[i].resize(w + 1);
		cin >> s;
		rep(j, w) {
			d[i][j + 1] = s[j] * Power(k, j) * Power(l, i - 1);
			d[i][j + 1] += d[i][j];
		}
	}
	rep(j, w + 1) {
		rep(i, h) {
			d[i + 1][j] += d[i][j];
		}
	}
	return;
}

int main(void) {
	int num, i, j, h, w;
	vector<vector<ull>> d, t;
	Input(d);
	Input(t);
	h = t.size() - 1 ;
	w = t[0].size() - 1;
	ull a = t[h][w];
	for (i = h; i < d.size(); i++) {
		for (j = w; j < d[i].size(); j++) {
			if (d[i][j] + d[i - h][j - w] - d[i - h][j] - d[i][j - w] == a * Power(k, j - w) * Power(l, i - h)) {
				printf("%d %d\n", i - h, j - w);
			}
		}
	}

	return 0;
}