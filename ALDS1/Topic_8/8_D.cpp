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

	node* insert(node* t, int key, int priority) {		// 再帰的に探索
		if (t == NULL) {
			node *buf = (node*)malloc(sizeof(node));
			*buf = node(key, priority);
			return buf;
		}												// 葉に到達したら新しい節点を生成して返す
		if (key == t->key)
			return t;									// 重複したkeyは無視
		if (key < t->key) {                             // 左の子へ移動
			t->left = insert(t->left, key, priority);   // 左の子へのポインタを更新
			if (t->priority < t->left->priority)        // 左の子の方が優先度が高い場合右回転
				t = rightRotate(t);
		}
		else {											// 右の子へ移動
			t->right = insert(t->right, key, priority); // 右の子へのポインタを更新
			if (t->priority < t->right->priority)       // 右の子の方が優先度が高い場合左回転
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
		if (key < t->key)                               // 削除対象を検索
			t->left = Delete(t->left, key);
		else if (key > t->key)
			t->right = Delete(t->right, key);
		else
			return _delete(t, key);
		return t;
	}

	node *_delete(node *t, int key) {					// 削除対象の節点の場合
		if (t->left == NULL && t->right == NULL)        // 葉の場合
			return NULL;
		else if (t->left == NULL)                       // 右の子のみを持つ場合左回転
			t = leftRotate(t);
		else if (t->right == NULL)                      // 左の子のみを持つ場合右回転
			t = rightRotate(t);
		else {											// 左の子と右の子を両方持つ場合
			if (t->left->priority > t->right->priority) // 優先度が高い方を持ち上げる
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