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

Node* reverseKNodes(Node*&head, int k){
    if(head == nullptr){
        cout<<"LL is empty"<<endl;
        return head;
    }
    int len = getLengthofLL(head);
    if(k>len){
        return head;
    }
    //reverse first K nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count =0;
    while(count<k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if(forward != NULL){
        //after reversing some nodes are left
        Node* recursionKaAns = reverseKNodes(forward,k);
        head->next = recursionKaAns;
    }
    head = prev;
    return head;
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
    reverseKNodes(head,3);
    printLL(head);

    return 0;
}