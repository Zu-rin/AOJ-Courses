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
	int num, i, t, ans = 0, s, e;
	cin >> num >> t;
	vector<int> d(t + 1, 0);
	rep(i, num) {
		cin >> s >> e;
		d[s]++;
		d[e]--;
	}
	rep(i, t) {
		d[i + 1] += d[i];
		chmax(ans, d[i]);
	}
	cout << ans << "\n";
	return 0;
}