/* Function to perform level order/BFS traversal of tree using a queue
The standard container classes DEQUE and LIST fulfill the requirements of QUEUE container adaptor. */

#include <iostream>
#include <cstdio>
#include <deque>                   // USING C++ STL :)
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

void levelOrder(node* root) {
    deque<node*> queue;
    while (root) {
        cout<<root -> data<<" ";
        if (root -> left)
            queue.push_back(root -> left);
        if (root -> right)
            queue.push_back(root -> right);
        if (!queue.empty()) {
            root = queue.front();
            queue.pop_front();
        }
        else return;
    }
    return;
}

node* createBinaryTree(node* root, int depth, int value) {
    if (depth < 1)
        return NULL;
    root = new node(value);
    root->left = createBinaryTree(root->left, depth-1, value*2);
    root->right = createBinaryTree(root->right, depth-1, value*2+1);
    return root;
}

int main() {
    freopen("input.txt","r",stdin);
    
    int depth;
    cin>>depth;
    node* root = createBinaryTree(root, depth, 1);
    cout<<"Level order traversal: "<<endl;
    levelOrder(root);
    cout<<endl;
    return 0;
}