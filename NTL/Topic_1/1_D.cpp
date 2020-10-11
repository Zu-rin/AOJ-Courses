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

int main(void) {
	ll num, i, ans, p;
	queue<ll> que;
	cin >> num;
	ans = num;
	if (!(num & 1)) {
		que.push(2);
		while (!(num & 1))
			num >>= 1;
	}
	for (p = 3; p < 35000 && num > 1; p += 2) {
		if (num % p == 0) {
			que.push(p);
			while (num % p == 0)
				num /= p;
		}
	}
	if (num > 1)
		que.push(num);
	while (!que.empty()) {
		p = que.front();
		que.pop();
		ans /= p;
		ans *= p - 1;
	}
	cout << ans << "\n";
	return 0;
}