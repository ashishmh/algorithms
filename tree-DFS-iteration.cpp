// Function to perform PRE, IN, POST or depth-first traversal of tree w/o recursion.

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void preorder(Node* root) {
	stack<Node*> stack;
	stack.push(root);
	while (!stack.empty()) {
		root = stack.top();
		stack.pop();
		cout<<root->data<<" ";
		if (root->right != NULL)
			stack.push(root->right);
		if (root->left != NULL)
			stack.push(root->left);
	}
}

void inorder(Node* root) {
	stack<Node*> stack;
	do {
		if (root != NULL) {
			stack.push(root);	
			root = root->left;
		}
		else {
			root = stack.top();
			stack.pop();
			cout<<root->data<<" ";
			root = root->right;
		}
	} while (!stack.empty() || root != NULL);
}

void postorder(Node* root) {
	stack<Node*> stack, temp;
	stack.push(root);
	while (!stack.empty()) {
		root = stack.top();
		stack.pop();
		temp.push(root);
		if (root->left)
			stack.push(root->left);
		if (root->right)
			stack.push(root->right);
	}
	while (!temp.empty()) {
		root = temp.top();
		temp.pop();
		cout<<root->data<<" ";
	}
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->right = new Node(8);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->left = new Node(9);

	cout<<"Preorder traversal  : ";
	preorder(root);
	cout<<endl<<"Inorder traversal   : ";
	inorder(root);
	cout<<endl<<"Postorder traversal : ";
	postorder(root);
	cout<<endl;
	return 0;
}