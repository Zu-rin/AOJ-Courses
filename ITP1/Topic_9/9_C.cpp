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
	int num, i, a = 0, b = 0;
	string s, t;
	cin >> num;
	rep(i, num) {
		cin >> s >> t;
		if (s > t)
			a += 3;
		else if (s < t)
			b += 3;
		else {
			a++; b++;
		}
	}
	printf("%d %d\n", a, b);
	return 0;
}