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

class LongestIncreasingSubsequence {
private:
	vector<ll> lis;

public:
	int Binary_search(ll n) {
		// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦š‚ğ•Ô‚·
		// n < min(lis) : -1
		// max(lis) < n : lis.size() - 1
		auto tag = upper_bound(lis.begin(), lis.end(), n);
		return distance(lis.begin(), tag) - 1;
	}

	int Add(ll newdata) {
		int k = Binary_search(newdata);
		if (k < 0 || newdata != lis[k]) {
			k++;
			if (k == lis.size())
				lis.push_back(newdata);
			else
				lis[k] = newdata;
		}
		return k;
	}

	int Size() {
		return (int)lis.size();
	}
};

int main(void) {
	int num, i, a;
	cin >> num;
	LongestIncreasingSubsequence lis;
	rep(i, num) {
		cin >> a;
		lis.Add(a);
	}
	cout << lis.Size() << "\n";
	return 0;
}