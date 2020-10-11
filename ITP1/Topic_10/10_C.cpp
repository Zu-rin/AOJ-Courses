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
	int num, i;
	double ans, ave;
	while (true) {
		cin >> num;
		if (num == 0)
			break;
		ans = ave = 0.0;
		vector<double> d(num);
		rep(i, num) {
			cin >> d[i];
			ave += d[i];
		}
		ave /= (double)num;
		rep(i, num) {
			ans += (d[i] - ave) * (d[i] - ave);
		}
		ans /= (double)num;
		ans = sqrt(ans);
		printf("%.10lf\n", ans);
	}
	return 0;
}