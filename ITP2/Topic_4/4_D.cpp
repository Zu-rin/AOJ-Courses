#include <iostream>
#include <vector>
#include <string>
#include <map>
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
	int num, i, d;
	map<int, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> d;
		mp[d];
	}
	auto itr = mp.begin();
	cout << (*itr).first;
	for (itr++; itr != mp.end(); itr++)
		printf(" %d", (*itr).first);
	printf("\n");
	return 0;
}