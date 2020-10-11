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
	vector<int> d(3);
	rep(i, 3)
		cin >> d[i];
	sort(d.begin(), d.end());
	rep(i, 2)
		cout << d[i] << " ";
	cout << d[2] << "\n";
	return 0;
}