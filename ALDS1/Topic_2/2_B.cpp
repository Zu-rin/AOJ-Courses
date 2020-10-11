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

int ans = 0;
void SelectSort(vector<int>& d) {
	int i, j, buf, mi;
	rep(i, d.size() - 1) {
		mi = i;
		for (j = i; j < d.size(); j++) {
			if (d[j] < d[mi])
				mi = j;
		}
		if (i != mi) {
			buf = d[i];
			d[i] = d[mi];
			d[mi] = buf;
			ans++;
		}
	}
}

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	SelectSort(d);
	rep(i, num - 1)
		cout << d[i] << " ";
	cout << d[i] << "\n";
	cout << ans << "\n";
	return 0;
}