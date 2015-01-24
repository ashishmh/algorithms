/* Function to perform level order/BFS traversal of tree using recursion */

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
        left = NULL;
        right = NULL;
    }
};

void printGivenLevel(node*, int);
int height(node*);

void levelOrderTraversal(node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printGivenLevel(root, i);
    return;
}

void printGivenLevel(node* root, int h) {
    if (!root)
        return;
    if (h == 1)
        cout<<root -> data<<" ";
    else if (h > 1) {
        printGivenLevel(root -> left, h-1);
        printGivenLevel(root -> right, h-1);
    }
    return;
}

int height(node* root) {
    if (!root)
        return 0;
    int lh = height(root -> left);
    int rh = height(root -> right);
    if (lh > rh)
        return lh+1;
    else
        return rh+1;
}

int main() {
    freopen("input.txt","r",stdin);

    node* root = new node(1);
        root -> left = new node(2);
        root -> right = new node(3);
        root -> left -> left = new node(4);
        root -> left -> right = new node(5);
        root -> right -> left = new node(6);
        root -> right -> right = new node(7);
    cout<<"BFS or level order traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}