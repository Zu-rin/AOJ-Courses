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
	int num, i, mi = INF, ma = -INF;
	ll sum = 0;
	cin >> num;
	vector<int> d(num);
	rep(i, num) {
		cin >> d[i];
		chmin(mi, d[i]);
		chmax(ma, d[i]);
		sum += d[i];
	}
	printf("%d %d %lld\n", mi, ma, sum);
	return 0;
}