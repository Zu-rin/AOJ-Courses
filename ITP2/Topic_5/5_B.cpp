#include <iostream>
#include <vector>
#include <string>
#include <tuple>
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
	int num, i, j, a, b;
	ll d;
	string c, e;
	cin >> num;
	vector<tuple<int, int, string, ll, string>> x(num);
	rep(i, num) {
		cin >> a >> b >> c >> d >> e;
		x[i] = make_tuple(a, b, c, d, e);
	}
	sort(x.begin(), x.end());
	rep(i, num) {
		cout << get<0>(x[i]) << " ";
		cout << get<1>(x[i]) << " ";
		cout << get<2>(x[i]) << " ";
		cout << get<3>(x[i]) << " ";
		cout << get<4>(x[i]) << "\n";
	}
	return 0;
}