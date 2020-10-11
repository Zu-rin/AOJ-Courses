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
	int num, i;
	cin >> num;
	vector<int> d(num + 1);
	d[0] = d[1] = 1;
	for(i = 2; i <= num; i++)
		d[i] = d[i - 1] + d[i - 2];
	cout << d[num] << "\n";
	return 0;
}