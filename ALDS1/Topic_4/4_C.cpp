#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
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
	int num, i;
	string s, a;
	map<string, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> s >> a;
		if (s == "insert")
			mp[a];
		else {
			if (mp.count(a))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}