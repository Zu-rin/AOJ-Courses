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

int main(void) {
	int num, i, a, b, ans;
	char s;
	while (true) {
		cin >> a >> s >> b;
		if (s == '+')
			ans = a + b;
		else if (s == '-')
			ans = a - b;
		else if (s == '*')
			ans = a * b;
		else if (s == '/')
			ans = a / b;
		else break;
		cout << ans << "\n";
	}
	return 0;
}