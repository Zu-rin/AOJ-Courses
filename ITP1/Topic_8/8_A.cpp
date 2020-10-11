#include <iostream>
#include <vector>
#include <string>
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
	int num, i;
	string s;
	getline(cin, s);
	rep(i, s.size()) {
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] += 32;
		else if('a' <= s[i] && s[i] <= 'z')
			s[i] -= 32;
	}
	cout << s << "\n";
	return 0;
}