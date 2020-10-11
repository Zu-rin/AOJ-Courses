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

vector<string> d;

void Search(int n, string s) {
	if (n == 0) {
		d.push_back(s);
		return;
	}
	int i;
	rep(i, 9) {
		if (n & (1 << i)) {
			string a = "1 ";
			a[0] += i;
			Search(n ^ (1 << i), s + a);
		}
	}
	return;
}

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦Žš‚ð•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(string n, vector<string> & d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, i, k;
	string s, a;
	cin >> num;
	rep(i, num) {
		cin >> a;
		s += a + " ";
	}
	Search((1 << num) - 1, "");
	k = Binary_search(s, d);
	if (k > 0) {
		d[k - 1][d[k].size() - 1] = '\n';
		cout << d[k - 1];
	}
	d[k][d[k].size() - 1] = '\n';
	cout << d[k];
	if (k < d.size() - 1) {
		d[k + 1][d[k].size() - 1] = '\n';
		cout << d[k + 1];
	}
	return 0;
}