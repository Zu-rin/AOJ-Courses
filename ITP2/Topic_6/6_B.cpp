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
	int n, m, i, j = 0, ok = true;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	rep(i, m)
		cin >> b[i];
	rep(i, m) {
		while (j < n && b[i] > a[j])
			j++;
		if (j == n || b[i] != a[j]) {
			ok = false;
			break;
		}
	}
	cout << ok << "\n";
	return 0;
}