#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, k, E, a, b;
	cin >> num >> E;
	vector<vector<ll>> d(num, vector<ll>(num, INF));
	rep(i, num)
		d[i][i] = 0;
	rep(i, E) {
		cin >> a >> b;
		cin >> d[a][b];
	}
	rep(k, num) {
		rep(i, num) {
			rep(j, num) {
				if(d[i][k] != INF && d[k][j] != INF)
					chmin(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	rep(k, num) {
		rep(i, num) {
			rep(j, num) {
				if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]) {
					printf("NEGATIVE CYCLE\n");
					return 0;
				}
			}
		}
	}
	rep(i, num) {
		rep(j, num - 1) {
			if (d[i][j] != INF)
				cout << d[i][j] << " ";
			else
				printf("INF ");
		}
		if (d[i][j] != INF)
			cout << d[i][j] << "\n";
		else
			printf("INF\n");
	}
	return 0;
}