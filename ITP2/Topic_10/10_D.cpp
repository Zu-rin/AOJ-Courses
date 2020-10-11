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

int Bitnum(unsigned long long num) {
	int ans = 0;
	while (num > 0) {
		if (num & 1ll)
			ans++;
		num >>= 1;
	}
	return ans;
}

int main(void) {
	int num, i, j, n, q, k;
	unsigned long long d = 0;
	ll all = -1ll;
	cin >> n;
	vector<unsigned long long> m(n, 0);
	rep(i, n) {
		cin >> q;
		rep(j, q) {
			cin >> k;
			m[i] |= 1ll << k;
		}
	}
	cin >> num;
	rep(i, num) {
		cin >> q >> k;
		if (q == 0)
			cout << ((d & (1ll << k)) > 0) << "\n";
		else if (q == 1)
			d |= m[k];
		else if (q == 2) {
			d |= m[k];
			d ^= m[k];
		}
		else if(q == 3)
			d ^= m[k];
		else if (q == 4)
			cout << ((d & m[k]) == m[k]) << "\n";
		else if (q == 5)
			cout << !((d & m[k]) == 0) << "\n";
		else if (q == 6)
			cout << ((d & m[k]) == 0) << "\n";
		else if (q == 7)
			cout << Bitnum(d & m[k]) << "\n";
		else
			cout << (d & m[k]) << "\n";
	}
	return 0;
}