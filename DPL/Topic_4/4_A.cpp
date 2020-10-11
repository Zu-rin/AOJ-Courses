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
int Binary_search(ll n, vector<ll> & d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, i, j, p = 0;
	ll v, ans = 0;
	cin >> num >> v;
	vector<vector<ll>> d(4, vector<ll>(num));
	vector<ll> ab(num * num), cd(num * num);
	rep(i, 4) {
		rep(j, num)
			scanf_s("%lld", &d[i][j]);
	}
	rep(i, num) {
		rep(j, num) {
			ab[p] = d[0][i] + d[1][j];
			cd[p++] = d[2][i] + d[3][j];
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	rep(i, ab.size())
		ans += Binary_search(v - ab[i], cd) - Binary_search(v - ab[i] - 1, cd);
	cout << ans << "\n";
	return 0;
}