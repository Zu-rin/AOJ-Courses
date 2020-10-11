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
	int num, i, n = 0, q;
	cin >> num;
	vector<int> d(num);
	rep(i, num) {
		cin >> q;
		if (q == 0) {
			cin >> d[n];
			n++;
		}
		else if (q == 1) {
			cin >> q;
			cout << d[q] << "\n";
		}
		else {
			n--;
		}
	}
	return 0;
}