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
	int num, i, ans;
	string s;
	while (true) {
		cin >> s;
		if (s[0] == '0')
			break;
		ans = 0;
		rep(i, s.size()) {
			ans += s[i] - '0';
		}
		cout << ans << "\n";
	}
	return 0;
}