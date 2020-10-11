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
typedef pair<ll, int> pp;

class HistArea {
private:
	stack<pp> st;
	ll ans;
	int p;

public:
	HistArea() {
		ans = p = 0;
	}

	void Add(ll n) {
		if (st.empty() || st.top().first < n) {
			st.push(make_pair(n, p));
		}
		else if (st.top().first > n) {
			auto a = st.top();
			while (!st.empty() && st.top().first > n) {
				a = st.top();
				st.pop();
				chmax(ans, a.first * (p - a.second));
			}
			st.push(make_pair(n, a.second));
		}
		p++;
		return;
	}

	ll Ans() {
		return ans;
	}
};

int main(void) {
	int num, i;
	ll a;
	HistArea d;
	cin >> num;
	rep(i, num) {
		cin >> a;
		d.Add(a);
	}
	d.Add(0);
	cout << d.Ans() << "\n";
	return 0;
}