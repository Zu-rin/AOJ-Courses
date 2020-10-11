#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ll num, i, g, ans;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	ans = d[0];
	rep(i, num) {
		ans = ans * d[i] / gcd(ans, d[i]);
	}
	cout << ans << "\n";
	return 0;
}