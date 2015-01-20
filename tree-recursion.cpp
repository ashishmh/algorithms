#include <iostream>
#include <cstdio>
#include <vector>					// USING C++ STL :)
using namespace std;

class tNode							// NODE FOR TREE
{
public:
	int data;
	tNode* left  = NULL;
	tNode* right = NULL;
};

void preorder(tNode* root) {
	vector<tNode*> stack;
	bool empty = false;
	while( !empty ) {
		if( root ) {
			cout<<root->data<<"\t";
			if( root->right )
				stack.push_back(root->right);
			root = root->left;
		} else {
			if( stack.size() !=0 ) {
				root = stack.back();
				stack.pop_back();
			} else
				empty = true;
		}
	}
}

void inorder(tNode* root) {
	vector<tNode*> stack;
	bool empty = false;
	while( !empty ) {
		if( root ) {
			stack.push_back(root);
			root = root->left;	
		} else {
			if( stack.size() != 0 ) {
				root = stack.back();
				stack.pop_back();
				cout<<root->data<<"\t";
				root = root->right;
			} else
				empty = true;
		}
	}
}

void postorder(tNode* root) {
	vector<tNode*> stack;
	bool empty = false;
	while( !empty ) {
		if( root ) {
			stack.push_back(root);
			root = root->left;
		} else {
			if( stack.size() != 0 ) {
				root = stack.back();
				if( !root->right ) {
					cout<<root->data<<"\t";
					stack.pop_back();
				}
				root = root->right;
			} else
				empty = true;
		}
	}
}

int main() {
	tNode* root = NULL;
	tNode n1,n2,n3,n4,n5,n6,n7;
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