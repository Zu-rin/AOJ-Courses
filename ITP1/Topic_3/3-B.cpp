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
	int n, i;
	for (i = 1; i <= 10000; i++) {
		cin >> n;
		if (n == 0)
			break;
		printf("Case %d: %d\n", i, n);
	}
	return 0;
}