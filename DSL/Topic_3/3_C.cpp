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

ll Combi(ll num) {
	return num * (num + 1) / 2;
}

int main(void) {
	int num, i, q, l, r;
	ll ans, x, sum;
	cin >> num >> q;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	rep(i, q) {
		cin >> x;
		l = r = sum = ans = 0;
		rep(r, num) {
			sum += d[r];
			while (sum > x)
				sum -= d[l++];
			ans += r - l + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}