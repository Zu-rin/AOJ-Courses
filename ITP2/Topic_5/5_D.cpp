#include <iostream>
#include <vector>
#include <string>
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

vector<string> d;

void Search(int n, string s) {
	if (n == 0) {
		d.push_back(s);
		return;
	}
	int i;
	rep(i, 9) {
		if (n & (1 << i)) {
			string a = "1 ";
			a[0] += i;
			Search(n ^ (1 << i), s + a);
		}
	}
	return;
}

int main(void) {
	int num, i;
	string s, a;
	cin >> num;
	rep(i, num) {
		cin >> a;
		s += a + " ";
	}
	Search((1 << num) - 1, "");
	rep(i, d.size()) {
		d[i][d[0].size() - 1] = '\n';
		cout << d[i];
	}
	return 0;
}