// mega tree traversal ->
// BFS and DFS using recursion and stack
// and level order using recursion and stack

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createBinaryTree(int height, int value);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void preorderIteration(node *root);
void inorderIteration(node *root);
void postorderIteration(node *root);
void postorderTwoStack(node *root);
void levelOrderIteration(node *root);
void levelOrderRecursion(node *root);
void printGivenLevel(node *root, int level);
int findHeight(node *root);

node* createBinaryTree(int height, int value) {
    if (height < 1)
        return NULL;
    node *root = new node(value);
    root->left = createBinaryTree(height-1, 2*value);
    root->right = createBinaryTree(height-1, 2*value+1);
    return root;
}

void preorder(node *root) {
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorderIteration(node *root) {
    stack<node*> stack;
    while (!stack.empty() || root != NULL) {
        if (root != NULL) {
            cout<<root->data<<" ";
            if (root->right != NULL)
                stack.push(root->right);
            root = root->left;
        }
        else {
            root = stack.top();
            stack.pop();
        }
    }
}

void inorderIteration(node *root) {
    stack<node*> stack;
    while (!stack.empty() || root != NULL) {
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
    }
}

void postorderIteration(node *root) {
    stack<node*> stack;
    do {
        if (root != NULL) {
            if (root->right != NULL)
                stack.push(root->right);
            stack.push(root);
            root = root->left;
        }
        else {
            root = stack.top();
            stack.pop();
            if (root->right != NULL && !stack.empty() && root->right == stack.top()) {
                node *temp = stack.top();
                stack.pop();
                stack.push(root);
                root = temp;
            }
            else {
                cout<<root->data<<" ";
                root = NULL;
            }
        }
    } while (!stack.empty());
}

void postorderTwoStack(node *root) {
    stack<node*> stack, temp;
    // modify preorder to NRL from NLR and save it to temp stack
    while (!stack.empty() || root != NULL) {
        if (root != NULL) {
            temp.push(root);
            if (root->left != NULL)
                stack.push(root->left);
            root = root->right;
        }
        else {
            root = stack.top();
            stack.pop();
        }
    }
    // print temp stack, so it becomes LRN
    while (!temp.empty()) {
        cout<<temp.top()->data<<" ";
        temp.pop();
    }
}

void levelOrderIteration(node *root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (root->left != NULL)
            q.push(root->left);
        if (root->right != NULL)
            q.push(root->right);
        cout<<root->data<<" ";
    }
}

void levelOrderRecursion(node *root) {
    if (root == NULL)
        return;
    int height = findHeight(root);
    for (int i = 1; i <= height; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(node *root, int level) {
    if (root == NULL)
        return;
    if (level == 1) {
        cout<<root->data<<" ";
        return;
    }
    else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int findHeight(node *root) {
    if (root == NULL)
        return 0;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if (lh > rh)
        return lh+1;
    else return rh+1;
}

int main() {
    node *root = createBinaryTree(3, 1);

    cout<<"post order.."<<endl;
    cout<<"recursive: ";
    postorder(root);
    cout<<endl<<"iteration: ";
    postorderTwoStack(root);

    cout<<endl<<endl<<"level order: ";
    levelOrderRecursion(root);

    cout<<endl<<endl;
}