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
	int num, i, j, a, b;
	string s, t;
	cin >> s >> num;
	rep(j, num) {
		cin >> t >> a >> b;
		if (t == "print") {
			for (i = a; i <= b; i++)
				cout << s[i];
			printf("\n");
		}
		else if (t == "reverse") {
			char c;
			rep(i, (b - a + 1) >> 1) {
				c = s[i + a];
				s[i + a] = s[b - i];
				s[b - i] = c;
			}
		}
		else {
			cin >> t;
			rep(i, t.size()) {
				s[i + a] = t[i];
			}
		}
	}
	return 0;
}