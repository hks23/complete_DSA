//remove duplicate nodes in a sorted Linked List
#include <bits/stdc++.h>
using namespace std;
class Node {
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
void printLL(Node*&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void RemoveDuplicates(Node*& head) {
    if (!head || !head->next) {
        return;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}


int main()
{
    Node *head = new Node(10);
    Node *node = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(30);
    Node *node4 = new Node(50);
    Node *tail = new Node(100);
    head->next = node;
    node->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = tail;


   printLL(head);
   RemoveDuplicates(head);
   printLL(head);

    return 0;
}
