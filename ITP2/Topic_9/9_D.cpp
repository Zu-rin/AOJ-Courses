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
	int num, i, a;
	map<int, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> a;
		mp[a];
	}
	cin >> num;
	rep(i, num) {
		cin >> a;
		if (mp.count(a))
			mp.erase(a);
		else
			mp[a];
	}
	for (auto it = mp.begin(); it != mp.end(); it++)
		cout << (*it).first << "\n";
	return 0;
}