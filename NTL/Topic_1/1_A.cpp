#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
	int num, i, k;
	cin >> num;
	k = sqrt(num);
	cout << num << ":";
	for (i = 2; i <= k; i++) {
		while (num % i == 0) {
			printf(" %d", i);
			num /= i;
		}
		if (num == 1)
			break;
	}
	if (num != 1)
		printf(" %d", num);
	cout << "\n";
	return 0;
}