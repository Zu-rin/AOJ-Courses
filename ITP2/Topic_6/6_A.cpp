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

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦š‚ğ•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(int n, vector<int> & d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, i, q, k, p;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	cin >> q;
	rep(i, q) {
		cin >> k;
		p = Binary_search(k, d);
		printf("%d\n", p >= 0 && k == d[p]);
	}
	return 0;
}