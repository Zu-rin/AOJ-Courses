#include <iostream>
#include <vector>
#include <string>
#include <list>
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
	int n, num, i, j, q, k, a;
	cin >> n >> num;
	vector<list<int>> d(n);
	rep(j, num) {
		cin >> q >> k;
		if (q == 0) {
			cin >> a;
			d[k].push_back(a);
		}
		else if (q == 1) {
			auto itr = d[k].begin();
			if(itr != d[k].end())
				cout << *itr;
			for (itr++; itr != d[k].end(); itr++)
				printf(" %d", *itr);
			printf("\n");
		}
		else {
			d[k].resize(0);
		}
	}
	return 0;
}