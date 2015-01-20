#include <iostream>
#include <cstdio>
using namespace std;
 
class node
{
    public:
        int data;
        node* next;
};

node* createNode(int val) {
    node* n = new node();
    n->data = val;
    n->next = NULL;
    return n;
}

node* createLinkedList(int size) {
    if(size) {
        node* start;
        node* ptr;
        start = ptr = createNode(1);
        for(int i=1; i<size; i++) {
            ptr->next = createNode(i+1);
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return start;
    }
    else return NULL;
}
 
void print(node* start) {
    if(start) {
        node* ptr = start;
        for(; ptr->next != NULL; ) {
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
        cout<<ptr->data<<endl;
        cout<<"End of linked list"<<endl;
        return;
    }
    return;
}
 
node* reversell(node* start) {
    if(start->next) {
        node* newstart = reversell(start->next);
        node* ptr = newstart;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = start;
        start->next = NULL;
        return newstart;
    }
    return start;
}

int main() {
    freopen("input.txt","r",stdin);
    
    int size = 0;
    cin>>size;
    node* start = createLinkedList(size);
    if(start) {
        cout<<endl<<"Original list"<<endl;
        print(start);
        node* reverse = reversell(start);
        cout<<"Reversed list"<<endl;
        print(reverse);
    } else cout<<"Enter a size greater than zero"<<endl;
    return 0;
}