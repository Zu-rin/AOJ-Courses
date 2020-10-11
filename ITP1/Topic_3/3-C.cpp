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
	int a, b, i;
	rep(i, 3000) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << min(a, b) << " " << max(a, b) << "\n";
	}
	return 0;
}