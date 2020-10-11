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
	int num, i, j, q, a, b, sum = 0;
	map<int, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> q >> a;
		if (q == 3) {
			cin >> b;
			while (a <= b && !mp.count(a))
				a++;
			while (a <= b && !mp.count(b))
				b--;
			if (a <= b) {
				auto s = mp.find(a), e = mp.find(b);
				for (; s != e; s++) {
					rep(j, (*s).second)
						cout << (*s).first << "\n";
				}
				rep(j, (*e).second)
				cout << (*e).first << "\n";
			}
		}
		else if (q == 2) {
			sum -= mp[a];
			mp.erase(a);
		}
		else if (q == 1) {
			if (mp.count(a))
				cout << mp[a] << "\n";
			else
				printf("0\n");
		}
		else {
			mp[a]++;
			sum++;
			cout << sum << "\n";
		}
	}
	return 0;
}
