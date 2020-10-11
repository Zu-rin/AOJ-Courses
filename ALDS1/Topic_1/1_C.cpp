#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

int IsPrime(int n) {
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	int num, i, ans = 0, a;
	cin >> num;
	rep(i, num) {
		cin >> a;
		if (IsPrime(a))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}