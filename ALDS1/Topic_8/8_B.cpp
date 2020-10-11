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

typedef struct Node {
	struct Node* l, * r;
	int val;
	Node(int n) {
		l = r = NULL;
		val = n;
	}
} node;

class BinaryTree {
	node* root;
	int size;

public:
	BinaryTree(int num) {
		root = NULL;
		size = 0;
	}

	void FormatNode(node*& n, int data) {
		n = (node*)malloc(sizeof(node));
		n->val = data;
		n->l = n->r = NULL;
		return;
	}

	void Insert(int data) {
		if (root == NULL)
			FormatNode(root, data);
		else {
			node* n = root, * p = NULL;
			while (n != NULL) {
				p = n;
				if (data < n->val)
					n = n->l;
				else
					n = n->r;
			}
			if (data < p->val)
				FormatNode(p->l, data);
			else {
				FormatNode(p->r, data);
			}
		}
		size++;
	}

	node* Search(node* n, const int data) {
		if (n == NULL || n->val == data)
			return n;
		if (data < n->val)
			return Search(n->l, data);
		return Search(n->r, data);
	}

	int Count(const int data) {
		if (Search(root, data) == NULL)
			return 0;
		else
			return 1;
	}

	void Inorder(node* n) {
		if (n->l != NULL)
			Inorder(n->l);
		printf(" %d", n->val);
		if (n->r != NULL)
			Inorder(n->r);
		return;
	}

	void Preorder(node* n) {
		printf(" %d", n->val);
		if (n->l != NULL)
			Preorder(n->l);
		if (n->r != NULL)
			Preorder(n->r);
		return;
	}

	void Print() {
		Inorder(root);
		printf("\n");
		Preorder(root);
		printf("\n");
		return;
	}
};

int main(void) {
	int num, i, a;
	string s;
	cin >> num;
	BinaryTree bt(num);
	rep(i, num) {
		cin >> s;
		if (s == "insert") {
			cin >> a;
			bt.Insert(a);
		}
		else if (s == "find") {
			cin >> a;
			if (bt.Count(a))
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			bt.Print();
	}
	return 0;
}