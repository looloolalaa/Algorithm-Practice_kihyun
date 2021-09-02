#include <iostream>
#include <queue>
using namespace std;

class Node {
private:
	int key;
	Node* left;
	Node* right;
public:
	Node(int k = 0, Node* l = NULL, Node* r = NULL) : key(k), left(l), right(r) {}
	int getKey() { return key; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	void setLeft(Node* n) { left = n; }
	void setRight(Node* n) { right = n; }

	bool isLeaf() { return left == NULL && right == NULL; }
	int getHeight() {
		if (this==NULL) return 0;
		return left->getHeight() > right->getHeight() ? left->getHeight() + 1 : right->getHeight() + 1;
	}

	int getHeightDiff() {
		return left->getHeight() - right->getHeight();
	}

	void insert(Node* n) {
		if (key == n->getKey()) {
			printf("Already exist\n");
			return;
		}
		else if (key > n->getKey()) {
			if (this->getLeft() == NULL) {
				this->setLeft(n);
				return;
			}
			else 
				left->insert(n);
		}
		else {
			if (this->getRight() == NULL) {
				this->setRight(n);
				return;
			}
			else
				right->insert(n);
		}
	}

	void inOrder() {
		if (this != NULL) {
			left->inOrder();
			printf("[%d] ", key);
			right->inOrder();
		}
	}

	void find(int k) {
		if (this == NULL) {
			printf("Not found ..\n");
			return;
		}
		else {
			if (key == k) {
				printf("found!\n");
				return;
			}
			else if (key > k) {
				left->find(k);
			}
			else {
				right->find(k);
			}
		}
	}

};

class AVLTree {
private:
	Node* root = NULL;
public:
	AVLTree(int k) { root = new Node(k); }
	bool isEmpty() { return root == NULL; }

	void find(int k) {
		root->find(k);
	}

	Node* rotateLL(Node* p) {
		Node* child = p->getLeft();
		p->setLeft(child->getRight());
		child->setRight(p);
		return child;
	}
	Node* rotateRR(Node* p) {
		Node* child = p->getRight();
		p->setRight(child->getLeft());
		child->setLeft(p);
		return child;
	}
	Node* rotateLR(Node* p) {
		Node* child = p->getLeft();
		p->setLeft(rotateRR(child));
		return rotateLL(p);
	}
	Node* rotateRL(Node* p) {
		Node* child = p->getRight();
		p->setRight(rotateLL(child));
		return rotateRR(p);
	}

	Node* reBalance(Node* p) {
		int diff = p->getHeightDiff();
		if (diff > 1) {
			Node* child = p->getLeft();
			if (child->getHeightDiff() > 0)
				return rotateLL(p);
			else
				return rotateLR(p);
		}
		else if (diff < -1) {
			Node* child = p->getRight();
			if (child->getHeightDiff() > 0)
				return rotateRL(p);
			else
				return rotateRR(p);
		}
		return p;
	}

	Node* insert(Node* parent, Node* n) {
		int p_key = parent->getKey();
		int key = n->getKey();
		if (p_key == key) {
			printf("Already Exist\n");
			return NULL;
		}
		else if (p_key > key) {
			if (parent->getLeft() == NULL)
				parent->setLeft(n);
			else
				parent->setLeft(insert(parent->getLeft(), n));
			return reBalance(parent);
		}
		else {
			if (parent->getRight() == NULL)
				parent->setRight(n);
			else
				parent->setRight(insert(parent->getRight(), n));
			return reBalance(parent);
		}
	}
	void insert(int k) {
		Node* n = new Node(k);
		if (isEmpty()) root = n;
		else {
			root = insert(root, n);
		}
	}


	void remove(int k) {
		//
	}

	int level(int k) {
		if (isEmpty()) {
			printf("tree is empty\n");
			return 0;
		}
		else {
			Node* p = root;
			int level = 1;
			while (p != NULL) {
				if (p->getKey() == k) {
					return level;
				}
				else if (p->getKey() > k) {
					p = p->getLeft();
					level++;
				}
				else {
					p = p->getRight();
					level++;
				}
			}
			printf("Not Found ,,\n");
			return 0;
		}
	}

	void display_level() {
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* poped = q.front();
			q.pop();
			if (poped != NULL) {
				printf("[%d] ", poped->getKey());
				q.push(poped->getLeft());
				q.push(poped->getRight());
			}
		}
		printf("\n");
	}

	void inOrder() {
		root->inOrder();
		printf("\n");
	}

};

int main() {
	AVLTree tree(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(2);
	tree.insert(1);
	tree.insert(5);
	tree.insert(3);
	tree.insert(6);
	tree.insert(4);

	tree.inOrder();
	tree.display_level();
}