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

vector<vector<int>> d(6, vector<int>(6));

void Init() {
	d[0] = { -1,2,4,1,3,-1 };
	d[1] = { 3,-1,0,5,-1,2 };
	d[2] = { 1,5,-1,-1,0,4 };
	d[3] = { 4,0,-1,-1,5,1 };
	d[4] = { 2,-1,5,0,-1,3 };
	d[5] = { -1,3,1,4,2,-1 };
	return;
}

int Search(int a, int b, vector<int>& x) {
	int i, j;
	rep(i, 6) {
		if (x[i] != a)
			continue;
		rep(j, 6) {
			if (x[j] == b)
				return d[i][j];
		}
	}
	return -1;
}

int Judge(vector<int> &x, vector<int> &y) {
	int i, j, k, ok = true;
	vector<int> a(101, -1);
	rep(i, 6) {
		rep(j, 6) {
			if (d[i][j] >= 0) {
				k = Search(x[i], x[j], y);
				if (k >= 0 && x[d[i][j]] != y[k])
					ok = false;
			}
		}
	}
	return ok;
}

int main(void) {
	Init();
	int num, i, j, ok = true;
	cin >> num;
	vector<vector<int>> a(num, vector<int>(6));
	rep(i, num) {
		rep(j, 6)
			cin >> a[i][j];
	}
	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			if (Judge(a[i], a[j])) {
				ok = false;
				break;
			}
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}