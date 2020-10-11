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
	int par, dep, left, right, sib, height, deg;
	string type;
} node;

class Tree {
private:
	vector<node> d;
	int root;

public:
	Tree(int num) {
		int i;
		d.resize(num);
		rep(i, num) {
			d[i].deg = 0;
			d[i].par = d[i].left = d[i].right = d[i].sib = -1;
		}
	}

	void Add() {
		int id, a, b;
		cin >> id >> a >> b;
		if (a >= 0) {
			d[id].left = a;
			d[a].par = id;
		}
		if (b >= 0) {
			d[id].right = b;
			d[b].par = id;
		}
		if (a >= 0 && b >= 0) {
			d[a].sib = b;
			d[b].sib = a;
		}
	}

	void SetType() {
		int i;
		rep(i, d.size()) {
			if (d[i].par == -1) {
				d[i].type = "root";
				root = i;
			}
			else if (d[i].left != d[i].right)
				d[i].type = "internal node";
			else
				d[i].type = "leaf";
		}
	}

	void SetAll() {
		SetType();
		d[root].dep = 0;
		SetDep(root);
	}

	int SetDep(int n) {
		if (d[n].type == "leaf")
			return d[n].height = 0;
		int a, b;
		a = b = 0;
		if (d[n].left >= 0) {
			d[n].deg++;
			d[d[n].left].dep = d[n].dep + 1;
			a = SetDep(d[n].left) + 1;
		}
		if (d[n].right >= 0) {
			d[n].deg++;
			d[d[n].right].dep = d[n].dep + 1;
			b = SetDep(d[n].right) + 1;
		}
		return d[n].height = max(a, b);
	}

	void Print(int i) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, d[i].par, d[i].sib, d[i].deg, d[i].dep, d[i].height);
		cout << d[i].type;
		printf("\n");
	}

};

int main(void) {
	int num, i, j, id, m;
	cin >> num;
	Tree tr(num);
	rep(i, num)
		tr.Add();
	tr.SetAll();
	rep(i, num) {
		tr.Print(i);
	}
	return 0;
}