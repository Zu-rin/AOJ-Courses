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

int Search(int num) {
	int ans = 0;
	ans += num / 25;
	num %= 25;
	ans += num / 10;
	num %= 10;
	ans += num / 5;
	num %= 5;
	ans += num;
	return ans;
}

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	ans = Search(num);
	cout << ans << "\n";
	return 0;
}