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
	int n, m, i, ans = 1;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	rep(i, m)
		cin >> b[i];
	rep(i, min(n, m)) {
		if (a[i] > b[i]) {
			ans = 0;
			break;
		}
		else if (a[i] < b[i]) {
			cout << ans << "\n";
			return 0;
		}
	}
	if (ans && n >= m)
		ans = 0;
	cout << ans << "\n";
	return 0;
}