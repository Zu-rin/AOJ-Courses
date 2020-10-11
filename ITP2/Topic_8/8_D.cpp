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
	int num, i, j, q, x;
	string s, t;
	map<string, vector<int>> mp;
	cin >> num;
	rep(i, num) {
		cin >> q >> s;
		if (q == 3) {
			cin >> t;
			auto itr = mp.begin(), e = mp.end();
			if (mp.count(s))
				itr = mp.find(s);
			else {
				mp[s];
				itr = mp.find(s);
				itr++;
				mp.erase(s);
			}
			if (mp.count(t)) {
				e = mp.find(t);
				e++;
			}
			else {
				mp[t];
				e = mp.find(t);
				e++;
				mp.erase(t);
			}
			for (; itr != e; itr++) {
				if (s <= (*itr).first) {
					rep(j, (*itr).second.size()) {
						cout << (*itr).first << " ";
						cout << (*itr).second[j] << "\n";
					}
				}
			}
		}
		else if (q == 2) {
			mp.erase(s);
		}
		else if (q == 1) {
			if (mp.count(s)) {
				rep(j, mp[s].size())
					cout << mp[s][j] << "\n";
			}
		}
		else {
			cin >> x;
			mp[s].push_back(x);
		}
	}
	return 0;
}