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

char Judge(int a, int b, int c) {
	int sum = a + b;
	if (a < 0 || b < 0 || sum < 30)
		return 'F';
	if (sum >= 80)
		return 'A';
	if (sum >= 65)
		return 'B';
	if (sum >= 50 || c >= 50)
		return 'C';
	else
		return 'D';
}

int main(void) {
	int num, i, a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a < 0 && b < 0 && c < 0)
			break;
		cout << Judge(a, b, c) << "\n";
	}
	return 0;
}