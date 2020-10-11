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
typedef struct Card{
	string s;
	int x, pos;
	bool operator<(const Card& r) {
		return x < r.x;
	}
	bool operator==(const Card& r) {
		return x == r.x;
	}
} card;

void Swap(vector<card>& d, const int a, const int b) {
	card buf = d[a];
	d[a] = d[b];
	d[b] = buf;
	return;
}

int Partition(vector<card>& d, int p, int r) {
	int x = d[r].x, i = p - 1;
	for (int j = p; j < r; j++) {
		if (d[j].x <= x) {
			i++;
			Swap(d, i, j);
		}
	}
	Swap(d, i + 1, r);
	return i + 1;
}

void QuickSort(vector<card>& d, int p, int r) {
	if (p < r) {
		int	q = Partition(d, p, r);
		QuickSort(d, p, q - 1);
		QuickSort(d, q + 1, r);
	}
}

int main(void) {
	int num, i, p, x, ok = true;
	cin >> num;
	string s;
	vector<card> d(num);
	rep(i, num) {
		cin >> s >> x;
		d[i] = { s, x, i };
	}
	QuickSort(d, 0, num - 1);
	rep(i, num - 1) {
		if (d[i] == d[i + 1] && d[i].pos > d[i + 1].pos) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("Stable\n");
	else
		printf("Not stable\n");
	rep(i, num) {
		cout << d[i].s << " " << d[i].x << "\n";
	}
	return 0;
}