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
	int num, i;
	ll sum = 0, k;
	double ans;
	cin >> num;
	vector<ll> x(num);
	rep(i, num)
		cin >> x[i];
	rep(i, num) {
		cin >> k;
		x[i] -= k;
		sum += abs(x[i]);
	}
	cout << sum << "\n";
	sum = 0;
	rep(i, num)
		sum += x[i] * x[i];
	ans = sqrt((double)sum);
	printf("%.10lf\n", ans);
	sum = 0;
	rep(i, num)
		sum += abs(x[i] * x[i] * x[i]);
	ans = pow(sum, 1.0 / 3.0);
	printf("%.10lf\n", ans);
	sum = 0;
	rep(i, num)
		chmax(sum, abs(x[i]));
	cout << sum << "\n";
	return 0;
}