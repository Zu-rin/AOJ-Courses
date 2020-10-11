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

class LimitationKnapsack {
// 個数制限付きナップサック問題を解く
// W: 重量限界値   N: 物の個数   M: 各物の個数制限値
// 時間計算量: O(N * W * logM)   空間計算量: O(W)
private:
	vector<vector<ll>> dp;
	int p, maxW;

public:
	LimitationKnapsack(int maxweight) {
		maxW = maxweight;
		dp.resize(2, vector<ll>(maxW + 1, 0));
		p = 0;
	}

	int Size(int n) {
		int ans = 0, num = n;
		while (n > 0) {
			ans++;
			n >>= 1;
		}
		if (num == (1 << ans) - 1)
			return ans;
		return ans - 1;
	}

	void Add(ll value, ll weight, ll num) {
		int i, j, a;
		ll nv, nw;
		while (num > 0) {
			a = Size(num);
			rep(j, a) {
				nv = value * (1 << j);
				nw = weight * (1 << j);
				rep(i, maxW + 1 - nw)
					dp[(p + 1) & 1][i + nw] = dp[p][i] + nv;
				rep(i, maxW + 1)
					chmax(dp[(p + 1) & 1][i], dp[p][i]);
				p = (p + 1) & 1;
			}
			num -= (1 << a) - 1;
		}
	}

	ll Ans() {
		return dp[p][maxW];
	}

};

int Size(int n) {
	int ans = 0, num = n;
	while (n > 0) {
		ans++;
		n >>= 1;
	}
	if (num == (1 << ans) - 1)
		return ans;
	return ans - 1;
}

int main(void) {
	int num, i, j, k, W, v, w, m, a, nv, nw, p = 0;
	cin >> num >> W;
	LimitationKnapsack dp(W);
	rep(i, num) {
		cin >> v >> w >> m;
		dp.Add(v, w, m);
	}
	cout << dp.Ans() << "\n";
	return 0;
}