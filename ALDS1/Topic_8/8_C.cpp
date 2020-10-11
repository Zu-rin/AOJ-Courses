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
	int key;
	Node* l, * r;

	Node(int k) {
		key = k;
		l = r = NULL;
	}
} node;

class BinaryTree {
	node* root;

public:
	BinaryTree() {
		root = NULL;
	}

	void Insert(const int k) {
		if (root == NULL) {
			root = (node*)malloc(sizeof(node));
			*root = Node(k);
			return;
		}
		node* p = root;
		node** tag;
		while (true) {
			if (p->key == k)
				return;
			if (k < p->key) {
				if (p->l == NULL) {
					tag = &(p->l);
					break;
				}
				p = p->l;
			}
			else {
				if (p->r == NULL) {
					tag = &p->r;
					break;
				}
				p = p->r;
			}
		}
		*tag = (node*)malloc(sizeof(node));
		**tag = Node(k);
	}

	node* Find(node* p, const int k) {
		if (p->key == k)
			return p;
		if (k < p->key) {
			if (p->l == NULL)
				return NULL;
			return Find(p->l, k);
		}
		else {
			if (p->r == NULL)
				return NULL;
			return Find(p->r, k);
		}
	}

	char Find(const int k) {
		node* p = root;
		if (p == NULL || Find(p, k) == NULL)
			return false;
		return true;
	}

	void Delete(node** p) {
		node* c = (*p);
		if (c->l == NULL && c->r == NULL) {
			(*p) = NULL;
		}
		else if (c->l != NULL && c->r != NULL) {
			if (c->r->l == NULL) {
				(*p)->key = c->r->key;
				Delete(&c->r);
			}
			else {
				c = c->r;
				while (c->l->l != NULL)
					c = c->l;
				(*p)->key = c->l->key;
				Delete(&c->l);
			}
		}
		else if (c->l != NULL) {
			*p = c->l;
		}
		else {
			*p = c->r;
		}
		return;
	}

	void Delete(int k) {
		if (root == NULL)
			return;
		if (root->key == k) {
			Delete(&root);
			return;
		}
		node* p = root;
		while (true) {
			if (k < p->key) {
				if (k == p->l->key) {
					Delete(&p->l);
					return;
				}
				else
					p = p->l;
			}
			else {
				if (k == p->r->key) {
					Delete(&p->r);
					return;
				}
				else
					p = p->r;
			}
		}
	}

	void Inorder(node *p) {
		if (p->l != NULL)
			Inorder(p->l);
		cout << " " << p->key;
		if (p->r != NULL)
			Inorder(p->r);
	}

	void Preorder(node* p) {
		cout << " " << p->key;
		if (p->l != NULL)
			Preorder(p->l);
		if(p->r != NULL)
			Preorder(p->r);
	}

	void Print() {
		node* p = root;
		Inorder(p);
		printf("\n");
		Preorder(p);
		printf("\n");
		return;
	}
};

int main(void) {
	int num, i, k;
	string s;
	BinaryTree tr;
	cin >> num;
	rep(i, num) {
		cin >> s;
		if (s == "insert") {
			cin >> k;
			tr.Insert(k);
		}
		else if (s == "find") {
			cin >> k;
			if (tr.Find(k))
				printf("yes\n");
			else
				printf("no\n");
		}
		else if (s == "delete") {
			cin >> k;
			tr.Delete(k);
		}
		else {
			tr.Print();
		}
	}
	return 0;
}