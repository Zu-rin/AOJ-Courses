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
	int num, i;
	string s = "", a = "a : ", b;
	vector<int> d(26, 0);
	while (true) {
		cin >> b;
		if (cin.eof())
			break;
		s += b;
	}
	rep(i, s.size()) {
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] += 'a' - 'A';
		if ('a' <= s[i] && s[i] <= 'z')
			d[s[i] - 'a']++;
	}
	rep(i, 26) {
		cout << a << d[i] << "\n";
		a[0]++;
	}
	return 0;
}