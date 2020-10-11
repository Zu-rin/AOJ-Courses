#include <iostream>
#include <vector>
#include <string>
#include <tuple>
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
	int num, i, E, s, a, b, c;
	cin >> num >> E >> s;
	vector<tuple<int, int, int>> edge(E);
	vector<int> ans(num, INF);
	rep(i, E) {
		cin >> a >> b >> c;
		edge[i] = make_tuple(a, b, c);
	}
	ans[s] = 0;
	rep(a, E) {
		rep(i, E) {
			if(ans[get<0>(edge[i])] != INF)
				chmin(ans[get<1>(edge[i])], ans[get<0>(edge[i])] + get<2>(edge[i]));
		}
	}
	c = 0;
	rep(i, E) {
		if (ans[get<0>(edge[i])] != INF && ans[get<1>(edge[i])] > ans[get<0>(edge[i])] + get<2>(edge[i])) {
			c = 1;
			break;
		}
	}
	if (c)
		printf("NEGATIVE CYCLE\n");
	else {
		rep(i, num) {
			if (ans[i] != INF)
				cout << ans[i] << "\n";
			else
				printf("INF\n");
		}
	}
	return 0;
}