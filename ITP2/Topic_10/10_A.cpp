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

string Binary(ll n, int len) {
	int i;
	char c;
	string ans = "";
	rep (i, len) {
		if (n & 1)
			ans += '1';
		else
			ans += '0';
		n >>= 1;
	}
	for (i = 0; i < len / 2; i++) {
		c = ans[i];
		ans[i] = ans[len - 1 - i];
		ans[len - 1 - i] = c;
	}
	return ans;
}

int main(void) {
	ll num, i;
	cin >> num;
	cout << Binary(num, 32) << "\n";
	cout << Binary((1ll << 32) - 1 - num, 32) << "\n";
	cout << Binary(num << 1, 32) << "\n";
	cout << Binary(num >> 1, 32) << "\n";
	return 0;
}