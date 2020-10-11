#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, a;
	string k = "SHCD";
	char s;
	cin >> num;
	map<char, vector<int>> mp;
	mp['S'].resize(13);
	mp['H'].resize(13);
	mp['C'].resize(13);
	mp['D'].resize(13);
	rep(i, num) {
		cin >> s >> a;
		mp[s][a - 1] = true;
	}
	rep(i, 4) {
		rep(j, 13) {
			if (!mp[k[i]][j])
				printf("%c %d\n", k[i], j + 1);
		}
	}
	return 0;
}