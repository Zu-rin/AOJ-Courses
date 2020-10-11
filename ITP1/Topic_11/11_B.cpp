#include <iostream>
#include <vector>
#include <string>
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
	int num, i, q, s, t;
	vector<vector<int>> d(6, vector<int>(6));
	vector<int> a(6), b(101, -1);
	d[0] = { -1,2,4,1,3,-1 };
	d[1] = { 3,-1,0,5,-1,2 };
	d[2] = { 1,5,-1,-1,0,4 };
	d[3] = { 4,0,-1,-1,5,1 };
	d[4] = { 2,-1,5,0,-1,3 };
	d[5] = { -1,3,1,4,2,-1 };
	rep(i, 6) {
		cin >> a[i];
		b[a[i]] = i;
	}
	cin >> q;
	rep(i, q) {
		cin >> s >> t;
		cout << a[d[b[s]][b[t]]] << "\n";
	}
	return 0;
}