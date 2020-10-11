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

void Swap(int& a, int& b) {
	int buf = a;
	a = b;
	b = buf;
	return;
}

int main(void) {
	int num, i, n, p;
	cin >> num;
	vector<int> d(num);
	rep(i, num) {
		cin >> d[i];
		n = i;
		p = max(0, (i - 1) >> 1);
		while (n) {
			if (d[p] < d[n]) {
				Swap(d[p], d[n]);
				n = p;
				p = (p - 1) >> 1;
			}
			else
				break;
		}
	}
	rep(i, num)
		printf(" %d", d[i]);
	printf("\n");
	return 0;
}