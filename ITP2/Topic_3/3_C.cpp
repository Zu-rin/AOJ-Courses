#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, q, l, r, k, ans;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	cin >> q;
	rep(j, q) {
		cin >> l >> r >> k;
		ans = 0;
		for (i = l; i < r; i++) {
			if (d[i] == k)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}