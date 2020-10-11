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
	int num, i, q;
	list<int> ls;
	auto p = ls.begin();
	cin >> num;
	rep(i, num) {
		cin >> q;
		if (q == 0) {
			cin >> q;
			ls.insert(p, q);
			p--;
		}
		else if (q == 1) {
			cin >> q;
			if (q > 0)
				p = next(p, q);
			else
				p = prev(p, -q);
		}
		else {
			p = ls.erase(p);
		}
	}
	for (auto itr = ls.begin(); itr != ls.end(); itr++)
		cout << *itr << "\n";
	return 0;
}