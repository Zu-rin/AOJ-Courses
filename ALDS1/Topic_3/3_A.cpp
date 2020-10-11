#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <stack>
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
	int num, i, a, b;
	string s;
	stack<int> st;
	getline(cin, s);
	rep(i, s.size()) {
		if (s[i] == ' ')
			continue;
		if ('0' <= s[i] && s[i] <= '9') {
			a = 0;
			while (s[i] != ' ') {
				a *= 10;
				a += s[i++] - '0';
			}
			st.push(a);
		}
		else {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			if (s[i] == '+')
				st.push(a + b);
			else if (s[i] == '-')
				st.push(b - a);
			else
				st.push(a * b);
		}
	}
	cout << st.top() << "\n";
	return 0;
}