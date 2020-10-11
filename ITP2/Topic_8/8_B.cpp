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
	int num, i, q, x;
	string s;
	map<string, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> q >> s;
		if (q == 2) {
			mp.erase(s);
		}
		else if (q == 1) {
			if (mp.count(s))
				cout << mp[s] << "\n";
			else
				printf("0\n");
		}
		else {
			cin >> x;
			mp[s] = x;
		}
	}
	return 0;
}