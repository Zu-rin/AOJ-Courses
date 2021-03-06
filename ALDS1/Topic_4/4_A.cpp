#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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
	int num, i, a, ans = 0;
	map<int, int> d;
	cin >> num;
	rep(i, num) {
		cin >> a;
		d[a];
	}
	cin >> num;
	rep(i, num) {
		cin >> a;
		if (d.count(a))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}