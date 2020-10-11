#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
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
	int num, i, n = 0, ans = 0;
	cin >> num;
	vector<pp> d(num);
	rep(i, num)
		cin >> d[i].second >> d[i].first;
	sort(d.begin(), d.end());
	rep(i, num) {
		if (d[i].second > n) {
			n = d[i].first;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}