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
	int num, i, h, w;
	while (true) {
		cin >> h >> w;
		if (h == 0)
			break;
		string a, b = "#";
		rep(i, w)
			a += "#";
		rep(i, w - 2)
			b += ".";
		b += "#";
		cout << a << "\n";
		rep(i, h - 2)
			cout << b << "\n";
		cout << a << "\n\n";
	}
	return 0;
}