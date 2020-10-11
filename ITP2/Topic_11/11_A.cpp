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

int main(void) {
	int num, i, k, a;
	cin >> num;
	rep(i, 1 << num) {
		printf("%d:", i);
		k = i;
		a = 0;
		while (k > 0) {
			if (k & 1)
				printf(" %d", a);
			k >>= 1;
			a++;
		}
		printf("\n");
	}
	return 0;
}