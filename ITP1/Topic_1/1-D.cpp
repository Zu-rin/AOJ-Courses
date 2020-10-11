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
	int num, i, h, m, s;
	cin >> num;
	s = num % 60;
	num /= 60;
	m = num % 60;
	h = num / 60;
	printf("%d:%d:%d\n", h, m, s);
	return 0;
}