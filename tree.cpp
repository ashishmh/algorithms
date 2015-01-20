#include <iostream>
#include <cstdio>
using namespace std;

class node
{
  	public:
  		int data;
		node* left  = NULL;
		node* right = NULL;
};

void preorder(node* root) {
	if( root == NULL )
		return;
	cout<<root->data<<"\t";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	if( root == NULL )
		return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

void postorder(node* root) {
	if( root == NULL )
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"\t";
}

int main() {
	node* root = NULL;
	node n1,n2,n3,n4,n5,n6,n7;
	root = &n1;
	n1.data = 1; n2.data = 2; n3.data = 3; n4.data = 4; n5.data = 5; n6.data = 6; n7.data = 7;
	n1.left   = &n2;
	n1.right  = &n3;
	n2.left   = &n4;
	n2.right  = &n5;
	n3.left   = &n6;
	n3.right  = &n7;
	cout<<"Preorder traversal  : ";
	preorder(root);
	cout<<endl<<"Inorder traversal   : ";
	inorder(root);
	cout<<endl<<"Postorder traversal : ";
	postorder(root);
	return 0;
}