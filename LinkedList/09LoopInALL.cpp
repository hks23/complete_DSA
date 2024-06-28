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

bool hasCycle(Node *head) {
        if(!head || !head->next) return false;

        Node* slow = head;
        Node* fast = head->next;
        bool cyclePresent = false;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast->next){
                fast=fast->next;
            }
            if(fast == slow){
                cyclePresent = true;
                break;
            }
        }
        return cyclePresent;
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

    tail->next = node3;  //making a cycle in the linked list
    //printLL(head);
    bool ans = hasCycle(head);
    cout<<ans<<endl;
   //printLL(head);

    return 0;
}
