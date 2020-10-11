#pragma GCC optimize("O3")
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
typedef pair<char, int> pp;

class SuffixArray {
	string s;
	vector<int> p;

public:
	/// <summary>
	/// Suffix Array 構築コンストラクタ
	/// O(N*(logN)^2)
	/// </summary>
	/// <param name="str">本文</param>
	/// <returns></returns>
	SuffixArray(const string str) {
		s = str;
		p = vector<int>(s.size());
		int i, x = 0, k;
		vector<vector<int>> rank(2, vector<int>(s.size()));
		rep(i, s.size()) {
			p[i] = i;
			rank[x][i] = s[i];
		}
		for (k = 1; k < s.size(); k <<= 1) {
			auto comp = [&](int i, int j) {
				if (rank[x][i] != rank[x][j])
					return rank[x][i] < rank[x][j];
				if (max(i, j) + k < s.size())
					return rank[x][i + k] < rank[x][j + k];
				if (j + k >= s.size())
					return false;
				return true;
			};
			sort(p.begin(), p.end(), comp);
			rank[!x][p[0]] = 0;
			rep(i, s.size() - 1) {
				rank[!x][p[i + 1]] = rank[!x][p[i]] + comp(p[i], p[i + 1]);
			}
			x = !x;
		}
	}

	/// <summary>
	/// 本文中に検索対象を検索
	/// O(M logN)  M: t.size()
	/// </summary>
	/// <param name="t">検索対象</param>
	/// <returns></returns>
	int Is_Exist(const string& t) {
		int l = 0, r = p.size() - 1, n, k;
		while (l < r) {
			n = (l + r) >> 1;
			k = t.compare(s.substr(p[n], t.size()));
			if (k) {
				if (k < 0)
					r = n;
				else
					l = n + 1;
			}
			else
				return 1;
		}
		return t.compare(s.substr(p[l], t.size())) == 0;
	}
};

int main(void) {
	int num, i, k, x = 0;
	string s, t;
	cin >> s >> num;
	SuffixArray sa(s);
	rep(i, num) {
		cin >> t;
		cout << sa.Is_Exist(t) << "\n";
	}
	return 0;
}