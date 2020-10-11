#include <iostream>
#include <vector>
#include <string>
#include <list>
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

int main(void) {
	int num, i, a;
	string s;
	priority_queue<int> que;
	while (true) {
		cin >> s;
		if (s == "insert") {
			cin >> a;
			que.push(a);
		}
		else if (s == "extract") {
			cout << que.top() << "\n";
			que.pop();
		}
		else
			break;
	}
	return 0;
}