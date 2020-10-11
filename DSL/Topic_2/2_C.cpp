#include <iostream>
#include <vector>
#include <string>
#include <map>
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
	int num, i, j, ax, ay, q, bx, by;
	cin >> num;
	map<int, map<int, int>> mp;
	rep(i, num) {
		cin >> ax >> ay;
		mp[ax][ay] = i;
	}
	cin >> q;
	rep(i, q) {
		cin >> ax >> bx >> ay >> by;
		vector<int> d;
		auto x = mp.begin();
		if (mp.count(ax))
			x = mp.find(ax);
		else {
			mp[ax];
			x = mp.erase(mp.find(ax));
		}
		for (; x != mp.end() && (*x).first <= bx; x++) {
			auto y = (*x).second.begin();
			if ((*x).second.count(ay))
				y = (*x).second.find(ay);
			else {
				(*x).second[ay];
				y = (*x).second.erase((*x).second.find(ay));
			}
			for (; y != (*x).second.end() && (*y).first <= by; y++) {
				d.push_back((*y).second);
			}
		}
		sort(d.begin(), d.end());
		rep(j, d.size())
			cout << d[j] << "\n";
		printf("\n");
	}
	return 0;
}