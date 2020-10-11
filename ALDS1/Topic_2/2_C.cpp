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

typedef struct data {
	char v, s;
	int p;
	bool operator<(const data& right) const {
		return v < right.v;
	}
} card;

void print(vector<card>& d) {
	int i, ok = true;
	rep(i, d.size() - 1) {
		cout << d[i].s << d[i].v << " ";
		if (d[i].v == d[i + 1].v && d[i].p > d[i + 1].p)
			ok = false;
	}
	cout << d[i].s << d[i].v << "\n";
	if (ok)
		printf("Stable\n");
	else
		printf("Not stable\n");
	return;
}

void BubbleSort(vector<card> d) {// N 個の要素を含む 0-オリジンの配列 A
	int i, flag = 1;
	card buf;
	while (flag) {
		flag = 0;
		for (i = d.size() - 1; i >= 1; i--) {
			if (d[i] < d[i - 1]) {
				buf = d[i];
				d[i] = d[i - 1];
				d[i - 1] = buf;
				flag = 1;
			}
		}
	}
	print(d);
}

void SelectSort(vector<card> d) {
	int i, j, mi;
	card buf;
	rep(i, d.size() - 1) {
		mi = i;
		for (j = i; j < d.size(); j++) {
			if (d[j] < d[mi])
				mi = j;
		}
		if (i != mi) {
			buf = d[i];
			d[i] = d[mi];
			d[mi] = buf;
		}
	}
	print(d);
}

int main(void) {
	int num, i;
	string a;
	cin >> num;
	vector<card> d(num);
	rep(i, num) {
		cin >> a;
		d[i] = { a[1], a[0], i };
	}
	BubbleSort(d);
	SelectSort(d);
	return 0;
}