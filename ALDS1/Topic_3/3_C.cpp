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

int main(void) {
	int num, i, k;
	string s;
	list<int> d;
	cin >> num;
	rep(i, num) {
		cin >> s;
		if (s[0] == 'i') {
			cin >> k;
			d.push_front(k);
		}
		else if (s == "delete") {
			cin >> k;
			for (auto it = d.begin(); it != d.end(); it++) {
				if (*it == k) {
					d.erase(it);
					break;
				}
			}
		}
		else if (s == "deleteFirst") {
			d.erase(d.begin());
		}
		else {
			auto it = d.end(); it--;
			d.erase(it);
		}
	}
	auto it = d.begin();
	cout << *it;
	for (it++; it != d.end(); it++) {
		cout << " " << *it;
	}
	printf("\n");
	return 0;
}