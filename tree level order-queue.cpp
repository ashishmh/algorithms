/* Function to perform level order/BFS traversal of tree using a queue
The standard container classes DEQUE and LIST fulfill the requirements of QUEUE container adapter. */

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
        left = NULL;
        right = NULL;
    }
};

void bfsTraversal(node* root) {
    deque<node*> queue;
    bool empty = false;
    while (!empty) {
        if (root) {
            cout<<root -> data<<" ";
            if (root -> left)
                queue.push_back(root -> left);
            if (root -> right)
                queue.push_back(root -> right);
            if (!queue.empty()) {
                root = queue.front();
                queue.pop_front();    
            } else
                empty = true;
        }
    }
    return;
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
    bfsTraversal(root);
    cout<<endl;
    return 0;
}