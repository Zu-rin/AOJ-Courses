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
	int num, i, k, l;
	string s, a;
	while (true) {
		cin >> a >> num;
		if (a == "-")
			break;
		s = a;
		l = 0;
		rep(i, num) {
			cin >> k;
			l += k;
			s += a;
		}
		rep(i, a.size()) {
			cout << s[l + i];
		}
		printf("\n");
	}
	return 0;
}