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

void Print(vector<int> & d) {
	for (int i = 0; i < d.size() - 1; i++)
		cout << d[i] << " ";
	cout << d[d.size() - 1] << "\n";
	return;
}

void InsertionSort(vector<int> & d) {
	int i, j, buf;
	for (i = 1; i < d.size(); i++) {
		buf = d[i];
		for (j = i - 1; j >= 0 && d[j] > buf; j--) {
			d[j + 1] = d[j];
		}
		d[j + 1] = buf;
		Print(d);
	}
}

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	Print(d);
	InsertionSort(d);
	return 0;
}