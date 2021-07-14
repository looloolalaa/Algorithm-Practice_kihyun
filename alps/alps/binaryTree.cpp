#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Node {
protected:
	int data;
	Node* left;
	Node* right;
public:
	Node(int val=0, Node* l=NULL, Node* r=NULL): data(val), left(l), right(r){}
	int getData() { return data; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	void setLeft(Node* n) { left = n; }
	void setRight(Node* n) { right = n; }
	bool isLeaf() { return left == NULL && right == NULL; }

	void preOrder(){
		printf("[%c] ", data);
		if (left != NULL) left->preOrder();
		if (right != NULL) right->preOrder();
	}

	void inOrder() {
		if (left != NULL) left->inOrder();
		printf("[%c] ", data);
		if (right != NULL) right->inOrder();
	}

	void postOrder() {
		if (left != NULL) left->postOrder();
		if (right != NULL) right->postOrder();
		printf("[%c] ", data);
	}

	int getCount() {
		if (this == NULL) return 0;
		else return 1 + left->getCount() + right->getCount();
	}

	int getHeight() {
		if (this == NULL) return 0;
		else {
			int hLeft = left->getHeight();
			int hRight = right->getHeight();
			return hLeft > hRight ? 1 + hLeft : 1 + hRight;
		}
	}

	int getLeafCount() {
		if (this == NULL) return 0;
		else if (isLeaf()) return 1;
		else return left->getLeafCount() + right->getLeafCount();
	}

	bool isBalanced() {
		if (this == NULL) return true;
		else if (height_gap() >= 2) return false;
		else return left->isBalanced() && right->isBalanced();
	}
	int height_gap() { return abs(left->getHeight() - right->getHeight()); }

	bool isComplete() { return left != NULL && right != NULL; }

	bool hasNode(Node* n) {
		if (this == NULL || n == NULL) return false;
		else return (this == n) || left->hasNode(n) || right->hasNode(n);
	}

};

class CircularQueue {
private:
	Node* data[MAX_SIZE];
	int front, rear;
public:
	CircularQueue(int f = 0, int r = 0) : front(f), rear(r) {}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_SIZE == front; }
	void enqueue(Node* n) {
		if (isFull()) printf("is Full\n");
		else {
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = n;
		}
	}
	Node* dequeue() {
		if (isEmpty()) printf("is Empty\n");
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
};

class BinaryTree {
private:
	Node* root;
public:
	BinaryTree(Node* n = NULL) : root(n) {}
	void setRoot(Node* n) { root = n; }
	bool isEmpty() { return root == NULL; }
	Node* getRoot() { return root; }

	void preOrder() { if (!isEmpty()) root->preOrder(); }
	void inOrder() { if (!isEmpty()) root->inOrder(); }
	void postOrder() { if (!isEmpty()) root->postOrder(); }

	int getCount() { return isEmpty() ? 0 : root->getCount(); }
	int getHeight() { return isEmpty() ? 0 : root->getHeight(); }
	int getLeafCount() { return isEmpty() ? 0 : root->getLeafCount(); }
	
	bool isFull(){
		if (root == NULL) return false;
		else {
			CircularQueue que;
			que.enqueue(root);
			while (!que.isEmpty()) {
				Node* node = que.dequeue();
				Node* nLeft = node->getLeft();
				Node* nRight = node->getRight();
				if (nLeft != NULL) que.enqueue(nLeft);
				if (nRight != NULL) que.enqueue(nRight);

				if (!node->isComplete()) {
					while (!que.isEmpty()) {
						if (!que.dequeue()->isLeaf())
							return false;
					}
					return true;
				}
			}
		}
		
	}
	int level(Node* n) {
		if (isEmpty()) return 0;
		else {

		}
	}
	bool isBalanced() { return isEmpty() ? true : root->isBalanced(); }
	int pathLength() { return isEmpty() ? 0 : level_sum(root); }
	int level_sum(Node* n) {
		if (n == NULL) return 0;
		else {
			printf("%d ", level(n) - 1);
			return level(n) - 1 + level_sum(n->getLeft()) + level_sum(n->getRight());
		}
	}

	bool reverse() {
		if (isEmpty()) return false;
		else {
			 reverse(root);
			 return true;
		}
	}

	Node* reverse(Node* n) {
		if (n == NULL) return NULL;
		Node* left_sub_tree = n->getLeft();
		Node* right_sub_tree = n->getRight();
		n->setLeft(reverse(right_sub_tree));
		n->setRight(reverse(left_sub_tree));
		return n;
	}

	bool hasNode(Node* n) {
		if (isEmpty()) return false;
		return root->hasNode(n);
	}

	bool isDisjointFrom(BinaryTree* that) {
		if (that->isEmpty()) return true;
		else {
			return !(hasNode(that->getRoot())
				|| hasNode(that->getRoot()->getLeft())
				|| hasNode(that->getRoot()->getRight()));
		}
	}

	bool isValid() {
		if (isEmpty()) return true;
		else {
			BinaryTree left_tree(root->getLeft());
			BinaryTree right_tree(root->getRight());
			return left_tree.isDisjointFrom(&right_tree);
		}
	}

	int getRootData() { return root->getData(); }
};

int main() {
	BinaryTree tree, that;
	Node* n1 = new Node('C', NULL, NULL);
	Node* n2 = new Node('D', NULL, NULL);
	Node* n3 = new Node('B', n1, n2);
	
	Node* n7 = new Node('G', NULL, NULL);
	
	Node* n4 = new Node('F', NULL, n7);
	Node* n5 = new Node('E', NULL, n4);
	Node* n6 = new Node('A', n3, n5);
	tree.setRoot(n6);

	//Node* n0 = new Node('Z', NULL, NULL);
	//that.setRoot(n0);
	
	cout << tree.isValid() << endl;
}