#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <queue>
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

int k = 1;
int DFS(int n, vector<vector<int>> & d, vector<int> & ord, vector<int> & low, set<int> &ans) {
	int c = 0;
	ord[n] = low[n] = k++;
	for (int a : d[n]) {
		if (ord[a]) {
			if(ord[a] < ord[n] - 1)
				chmin(low[n], ord[a]);
		}
		else {
			chmin(low[n], DFS(a, d, ord, low, ans));
			if (n != 0 && ord[n] <= low[a])
				ans.insert(n);
			c++;
		}
	}
	if(n == 0 && c > 1)
		ans.insert(0);
	return low[n];
}

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	vector<vector<int>> d(num);
	vector<int> ord(num, 0), low(num, INF);
	set<int> ans;
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	DFS(0, d, ord, low, ans);
	for (int a : ans)
		cout << a << "\n";
	return 0;
}