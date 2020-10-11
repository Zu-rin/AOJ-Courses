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

void Swap(vector<int> & d, const int a, const int b) {
	int buf = d[a];
	d[a] = d[b];
	d[b] = buf;
	return;
}

int Partition(vector<int> & d, int l, int p) {
	int a = l, b = p - 1;
	while (a < b) {
		while (d[a] < d[p])
			a++;
		while (d[p] < d[b])
			b--;
		if (a < b)
			Swap(d, a, b);
	}
	Swap(d, p, a);
	return a;
}

int partition(vector<int>& d, int p, int r) {
	int x = d[r], i = p - 1;
	for (int j = p; j < r; j++) {
		if (d[j] <= x) {
			i++;
			Swap(d, i, j);
		}
	}
	Swap(d, i + 1, r);
	return i + 1;
}

int main(void) {
	int num, i, p;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	p = partition(d, 0, num - 1);
	rep(i, p)
		cout << d[i] << " ";
	printf("[%d]", d[p]);
	for (i = p + 1; i < num; i++)
		cout << " " << d[i];
	printf("\n");
	return 0;
}