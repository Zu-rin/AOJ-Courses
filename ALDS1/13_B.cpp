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
#define INF 50

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

string Swap(const string & s, int a, int b) {
	string ans = s;
	char buf = ans[a];
	ans[a] = ans[b];
	ans[b] = buf;
	return ans;
}

void Push(map<int, char> & ans, queue<int> & que, const int n, const int x) {
	if (!ans[x]) {
		ans[x] = ans[n] + 1;
		que.push(x);
	}
	return;
}

int Search(int n) {
	map<int, char> ans;
	int i, p, x, g = 123456780;
	string s;
	queue<int> que;
	que.push(n);
	ans[n] = 1;
	while (true) {
		n = que.front();
		if (n == g)
			return ans[g];
		s = to_string(que.front());
		que.pop();
		p = s.find("0");
		if (p < 0) {
			s = "0" + s;
			p = 0;
		}
		if (p >= 3) {
			x = stoi(Swap(s, p, p - 3));
			Push(ans, que, n, x);
		}
		if (p < 6) {
			x = stoi(Swap(s, p, p + 3));
			Push(ans, que, n, x);
		}
		if (p % 3) {
			x = stoi(Swap(s, p, p - 1));
			Push(ans, que, n, x);
		}
		if (p % 3 != 2) {
			x = stoi(Swap(s, p, p + 1));
			Push(ans, que, n, x);
		}
	}
}

int main(void) {
	int num = 9, i, ans, a = 0, c;
	rep(i, num) {
		cin >> c;
		a *= 10;
		a += c;
	}
	ans = Search(a);
	cout << ans - 1 << "\n";
	return 0;
}