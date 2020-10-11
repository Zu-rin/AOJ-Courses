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

typedef struct {
	int par, dep;
	string type;
	list<int> child;
} node;

class Tree {
private:
	vector<node> d;
	int root;

public:
	Tree(int num) {
		int i;
		d.resize(num);
		rep(i, num)
			d[i].par = -1;
	}

	void Add() {
		int id, num, i, a;
		cin >> id >> num;
		rep(i, num) {
			cin >> a;
			d[id].child.push_back(a);
			d[a].par = id;
		}
	}

	void SetType() {
		int i;
		rep(i, d.size()) {
			if (d[i].par == -1) {
				d[i].type = "root, [";
				root = i;
			}
			else if (d[i].child.size())
				d[i].type = "internal node, [";
			else
				d[i].type = "leaf, [";
		}
	}

	void SetDep() {
		SetType();
		d[root].dep = 0;
		SetDep(root);
	}

	void SetDep(int n) {
		for (auto it = d[n].child.begin(); it != d[n].child.end(); it++) {
			d[*it].dep = d[n].dep + 1;
			SetDep(*it);
		}
	}

	void Print(int i) {
		printf("node %d: parent = %d, depth = %d, ", i, d[i].par, d[i].dep);
		cout << d[i].type;
		if (d[i].child.size()) {
			auto it = d[i].child.begin();
			cout << *it;
			for (it++; it != d[i].child.end(); it++) {
				cout << ", " << *it;
			}
		}
		printf("]\n");
	}

};

int main(void) {
	int num, i, j, id, m;
	cin >> num;
	Tree tr(num);
	rep(i, num)
		tr.Add();
	tr.SetDep();
	rep(i, num) {
		tr.Print(i);
	}
	return 0;
}