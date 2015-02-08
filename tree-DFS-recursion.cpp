/* Function to perform PRE, IN, POST or depth-first traversal of tree using recursion. */

#include <iostream>
#include <cstdio>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

node* createBinaryTree(node* root, int depth, int value) {
	if (depth < 1)
		return NULL;
	root = new node(value);
	root->left = createBinaryTree(root->left, depth-1, value*2);
	root->right = createBinaryTree(root->right, depth-1, value*2+1);
	return root;
}

void preorder(node* root) {
	if (!root)
		return;
	cout<<root -> data<<" ";
	preorder(root->left);
	preorder(root->right);
	return;
}

void inorder(node* root) {
	if (!root)
		return;
	inorder(root->left);
	cout<<root -> data<<" ";
	inorder(root->right);
	return;
}

void postorder(node* root) {
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root -> data<<" ";
	return;
}

int main() {
    freopen("input.txt","r",stdin);

    int depth;
    cin>>depth;
    node* root;
    root = createBinaryTree(root, depth, 1);
    cout<<"Preorder traversal  : ";
	preorder(root);
	cout<<endl<<"Inorder traversal   : ";
	inorder(root);
	cout<<endl<<"Postorder traversal : ";
	postorder(root);
	cout<<endl;
    return 0;
}