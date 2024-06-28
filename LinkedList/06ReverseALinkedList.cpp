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
// Reverse a linked list using Recursion
Node *reverseALlinkedListUisngRecursion(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        // LL is empty
        return prev; // prev me NULL pointer pass kiya hua hai
    }
    // solve 1 case rest recursion handles
    Node *forward = curr->next;
    curr->next = prev;
    reverse(curr, forward);
}
// Reverse a linked list using Iteration/loop
Node *reverseALinkedListUisngLoop(Node *&prev, Node *&curr)
{
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev; // prev pntr ko return kar diya
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

    // Example usage:
    // Node *prev1 = NULL;
    // reverseALlinkedListUisngRecursion(prev1, head);
    Node *prev2 = NULL;
    reverseALinkedListUisngLoop(prev2, head);
    printLL(tail);
    return 0;
}