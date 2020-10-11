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
	int num, i, buf;
	cin >> num;
	for (i = 3; i <= num; i++) {
		if (i % 3 == 0)
			cout << " " << i;
		else {
			buf = i;
			while (buf > 0) {
				if (buf % 10 == 3) {
					cout << " " << i;
					break;
				}
				buf /= 10;
			}
		}
	}
	printf("\n");
	return 0;
}