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

string v = "SWEN";
int Reverse(int n, int i, string & s, vector<vector<int>> & d) {
	if (i < 0)
		return n;
	return Reverse(d[v.find(s[i])][n], i - 1, s, d);
}

int main(void) {
	int num, i, ans;
	vector<vector<int>> d(4, vector<int>(6));
	vector<int> a(6);
	string s;
	d[0] = { 4,0,2,3,5,1 };
	d[1] = { 2,1,5,0,4,3 };
	d[2] = { 3,1,0,5,4,2 };
	d[3] = { 1,5,2,3,0,4 };
	rep(i, 6)
		cin >> a[i];
	cin >> s;
	ans = a[Reverse(0, s.size() - 1, s, d)];
	cout << ans << "\n";
	return 0;
}