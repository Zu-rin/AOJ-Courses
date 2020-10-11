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
	int num, x, i, j, k, ans;
	while (true) {
		cin >> num >> x;
		if (num == 0)
			break;
		ans = 0;
		for (i = 1; i <= num; i++) {
			for (j = i + 1; j <= num; j++) {
				for (k = j + 1; k <= num; k++) {
					if (i + j + k == x) {
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}