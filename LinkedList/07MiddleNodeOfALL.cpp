#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int getLengthofLL(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
Node* getMiddleNode(Node*&head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return head;
    }
    if(head->next == NULL){
        //only 1 node is present
        return head;
    }
    //LL has more than two nodes
    Node* slow = head; //ek ek step chalega
    Node* fast = head; //ek baar me do step chalega
    while(slow!= NULL and fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int main()
{
    Node *head = new Node(10);
    Node *node = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *node4 = new Node(50);
    Node *tail = new Node(100);
    head->next = node;
    node->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = tail;
    printLL(head);
    cout<<getMiddleNode(head)->data<<endl;
    return 0;
}