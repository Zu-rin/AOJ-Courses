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
	int num, i, j, h, w, ans;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	vector<int> b(w);
	rep(i, h) {
		rep(j, w)
			cin >> a[i][j];
	}
	rep(i, w)
		cin >> b[i];
	rep(i, h) {
		ans = 0;
		rep(j, w) {
			ans += a[i][j] * b[j];
		}
		cout << ans << "\n";
	}
	return 0;
}