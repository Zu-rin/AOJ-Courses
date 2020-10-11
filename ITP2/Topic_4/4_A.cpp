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

void Reverse(int l, int r, vector<int> & d) {
	if (l >= r)
		return;
	int buf = d[l];
	d[l] = d[r];
	d[r] = buf;
	Reverse(l + 1, r - 1, d);
	return;
}

int main(void) {
	int num, i, q, l, r;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	cin >> q;
	rep(i, q) {
		cin >> l >> r;
		Reverse(l, r - 1, d);
	}
	rep(i, num - 1)
		printf("%d ", d[i]);
	printf("%d\n", d[i]);
	return 0;
}