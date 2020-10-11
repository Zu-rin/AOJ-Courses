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

void Reverse(stack<pp> & st) {
	if (st.empty())
		return;
	pp a = st.top();
	st.pop();
	Reverse(st);
	cout << " " << a.second;
	return;
}

int main(void) {
	int num = 0, i, ans = 0;
	stack<int> st;
	stack<pp> a;
	string s;
	cin >> s;
	rep(i, s.size()) {
		if (s[i] == '\\') {
			st.push(i);
		}
		else if (s[i] == '/') {
			if (st.empty())
				continue;
			int v = i - st.top();
			ans += v;
			while (!a.empty() && st.top() < a.top().first) {
				v += a.top().second;
				a.pop();
			}
			a.push(pp(i, v));
			st.pop();
		}
	}
	cout << ans << "\n";
	cout << a.size();
	Reverse(a);
	printf("\n");
	return 0;
}