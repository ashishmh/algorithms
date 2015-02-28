// Implementation of binary search tree and its functions

#include <iostream>
#include <cstdio>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

class BST {
public:
    node* root;
    int size;
    BST(node* root, int size) {
    	this->root = root;
    	this->size = size;
    }
};

node* treeSearchRecursive(BST* T, int key);
node* treeSearchIterative(BST* T, int key);
node* treeMin(BST* T);
node* treeMax(BST* T);
node* treeSuccessor(BST* T, node* x);
void treeInsert(BST* T, int key);
void treeDelete(BST* T, int key);
void inorder(BST* T);

node* treeSearchRecursive(BST* T, int key) {
	node* root = T->root;
	if (!root || root->data == key)
		return root;
	if (key < root->data)
		return treeSearchRecursive(new BST(root->left, T->size), key);
	else return treeSearchRecursive(new BST(root->right, T->size), key);
}

node* treeSearchIterative(BST* T, int key) {
	node* root = T->root;
	while (root && root->data != key) {
		if (key < root->data)
			root = root->left;
		else root = root->right;
	}
	return root;
}

node* treeMin(BST* T) {
	node* root = T->root;
	while (root->left)
		root = root->left;
	return root;
}

node* treeMax(BST* T) {
	node* root = T->root;
	while (root->right)
		root = root->right;
	return root;
}

node* treeSuccessor(BST* T, node* x) {
	node* root = T->root;
	if (x->right)
		return treeMin(new BST(root->right, T->size));
	node* succ = NULL;
	while (root) {
		if (x->data < root->data) {
			succ = root;
			root = root->left;		
		}
		else root = root->right;
	}
	return succ;
}

void treeInsert(BST* T, int key) {
	node* root = T->root;
	if (!root) {
		T->root = new node(key);
		++(T->size);
		return;
	}
	while (root->left || root->right) {
		if (key <= root->data)
			root = root->left;
		else root = root->right;
	}
	if (key <= root->data)
		root->left = new node(key);
	else root->right = new node(key);
	++(T->size);
	return;
}

void treeDelete(BST* T, int key) {
	node* root = T->root;
	if (!root)
		return;
	node* ptr = root;
	node* p;
	node* parent = NULL;
	while (ptr && ptr->data != key) {
		parent = ptr;
		if (key <= ptr->data)
			ptr = ptr->left;
		else ptr = ptr->right;
	}
	// checking if key exists in BST
	if (!ptr) {
		cout<<"Element doesnt exist in BST.."<<endl;
		return;
	}

	p = ptr;
	if (!p->left) {
		if (!parent)
			T->root = p->right;
		else if (p == parent->left)
			parent->left = p->right;
		else parent->right = p->right;
	}
	else if (!p->right) {
		if (!parent)
			T->root = p->left;
		else if (p == parent->left)
			parent->left = p->left;
		else parent->right = p->left;
	}
	else {
		node* succ = p->right;
		node* succ_parent = p;
		while (succ->left) {
			succ_parent = succ;
			succ = succ->left;
		}
		if (!parent)
			T->root = succ;
		else if (p == parent->left)
			parent->left = succ;
		else parent->right = succ;
		if (succ == succ_parent->left)
			succ_parent->left = succ->right;
		else succ_parent->right = succ->right;
		succ->left = p->left;
		succ->right = p->right;
	}
	--(T->size);
	return;
}

void inorder(BST* T) {
	node* root = T->root;
	if (root) {
		inorder(new BST(root->left, T->size));
		cout<<root->data<<" ";
		inorder(new BST(root->right, T->size));
	}
	return;
}

int main() {
    freopen("input.txt","r",stdin);

    // hard-coding a BST
    node* root = new node(15);
    root->left = new node(6);
    root->right = new node(18);
    root->left->left = new node(3);
    root->left->right = new node(7);
    root->right->left = new node(17);
    root->right->right = new node(20);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    root->left->right->right = new node(13);
    root->left->right->right->left = new node(9);

    BST* T = new BST(root, 11);
    node* result;

    cout<<"Inorder traversal of BST : ";
    inorder(T);
    
    cout<<endl<<"BST recursive search (20) : ";
	result = treeSearchRecursive(T, 20);
	if (result)
		cout<<"Element found.."<<endl;
	else cout<<"Element not found.."<<endl;
    
    cout<<"BST iterative search (100) : ";
	result = treeSearchIterative(T, 100);
	if (result)
		cout<<"Element found.."<<endl;
	else cout<<"Element not found.."<<endl;
    
    cout<<"BST min element : ";
    result = treeMin(T);
    cout<<result->data<<endl;
    
    cout<<"BST max element : ";
    result = treeMax(T);
    cout<<result->data<<endl;
    
    cout<<"BST successor of 13 : ";
    result = treeSuccessor(T, T->root->left->right->right); 
    if (result)
		cout<<result->data<<endl;
	else cout<<"No successor.."<<endl;

	cout<<endl<<"Old size of tree: "<<T->size<<endl;
    cout<<"Inserting element 1, 8 and 21 in BST : ";
	treeInsert(T, 1);
	treeInsert(T, 8);
	treeInsert(T, 21);
    inorder(T);
	cout<<endl<<"New size of tree: "<<T->size<<endl;

    cout<<endl<<"Deleting element 15 in BST : ";
    treeDelete(T, 15);
    inorder(T);
	cout<<endl<<"Size of tree after deleting: "<<T->size<<endl;
    cout<<endl;
    return 0;
}