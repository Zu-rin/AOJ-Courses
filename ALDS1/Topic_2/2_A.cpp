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

int ans = 0;
void BubbleSort(vector<int> & d) {// N 個の要素を含む 0-オリジンの配列 A
	int i, buf, flag = 1;
	while (flag) {
		flag = 0;
		for (i = d.size() - 1; i >= 1; i--) {
			if (d[i] < d[i - 1]) {
				buf = d[i];
				d[i] = d[i - 1];
				d[i - 1] = buf;
				flag = 1;
				ans++;
			}
		}
	}
}

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	BubbleSort(d);
	rep(i, num - 1)
		cout << d[i] << " ";
	cout << d[i] << "\n";
	cout << ans << "\n";
	return 0;
}