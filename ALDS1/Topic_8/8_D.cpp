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
	int key, priority;
	Node* right, * left;
	Node(int k, int p) {
		key = k;
		priority = p;
		right = left = NULL;
	}
} node;

class Treap {
	node* root;

public:
	Treap() {
		root = NULL;
	}

	node* Root() {
		return root;
	}

	node* rightRotate(node* t) {
		node* s = t->left;
		t->left = s->right;
		s->right = t;
		if (root == t)
			root = s;
		return s;
	}
	node* leftRotate(node* t) {
		node* s = t->right;
		t->right = s->left;
		s->left = t;
		if (root == t)
			root = s;
		return s;
	}

	node* insert(node* t, int key, int priority) {		// �ċA�I�ɒT��
		if (t == NULL) {
			node *buf = (node*)malloc(sizeof(node));
			*buf = node(key, priority);
			return buf;
		}												// �t�ɓ��B������V�����ߓ_�𐶐����ĕԂ�
		if (key == t->key)
			return t;									// �d������key�͖���
		if (key < t->key) {                             // ���̎q�ֈړ�
			t->left = insert(t->left, key, priority);   // ���̎q�ւ̃|�C���^���X�V
			if (t->priority < t->left->priority)        // ���̎q�̕����D��x�������ꍇ�E��]
				t = rightRotate(t);
		}
		else {											// �E�̎q�ֈړ�
			t->right = insert(t->right, key, priority); // �E�̎q�ւ̃|�C���^���X�V
			if (t->priority < t->right->priority)       // �E�̎q�̕����D��x�������ꍇ����]
				t = leftRotate(t);
		}
		return t;
	}

	void insert(int key, int priority) {
		root = insert(root, key, priority);
		return;
	}

	node *Delete(node *t, int key) {
		if (t == NULL)
			return NULL;
		if (key < t->key)                               // �폜�Ώۂ�����
			t->left = Delete(t->left, key);
		else if (key > t->key)
			t->right = Delete(t->right, key);
		else
			return _delete(t, key);
		return t;
	}

	node *_delete(node *t, int key) {					// �폜�Ώۂ̐ߓ_�̏ꍇ
		if (t->left == NULL && t->right == NULL)        // �t�̏ꍇ
			return NULL;
		else if (t->left == NULL)                       // �E�̎q�݂̂����ꍇ����]
			t = leftRotate(t);
		else if (t->right == NULL)                      // ���̎q�݂̂����ꍇ�E��]
			t = rightRotate(t);
		else {											// ���̎q�ƉE�̎q�𗼕����ꍇ
			if (t->left->priority > t->right->priority) // �D��x���������������グ��
				t = rightRotate(t);
			else
				t = leftRotate(t);
		}
		return Delete(t, key);
	}

	char Find(node *t, int key) {
		if (t == NULL)
			return 0;
		if (key < t->key)
			return Find(t->left, key);
		if (key > t->key)
			return Find(t->right, key);
		return 1;
	}

	void Inorder(node* p) {
		if (p == NULL)
			return;
		if (p->left != NULL)
			Inorder(p->left);
		printf(" %d", p->key);
		if (p->right != NULL)
			Inorder(p->right);
		return;
	}

	void Preorder(node* p) {
		if (p == NULL)
			return;
		printf(" %d", p->key);
		if (p->left != NULL)
			Preorder(p->left);
		if (p->right != NULL)
			Preorder(p->right);
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
	int num, i, k, p;
	string s;
	Treap tr;
	cin >> num;
	rep(i, num) {
		cin >> s;
		if (s == "insert") {
			cin >> k >> p;
			tr.insert(k, p);
		}
		else if (s == "find") {
			cin >> k;
			if (tr.Find(tr.Root(), k))
				printf("yes\n");
			else
				printf("no\n");
		}
		else if (s == "delete") {
			cin >> k;
			tr.Delete(tr.Root(), k);
		}
		else {
			tr.Print();
		}
	}
	return 0;
}