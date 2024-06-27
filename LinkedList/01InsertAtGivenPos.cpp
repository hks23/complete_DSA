#include <iostream>
using namespace std;
// Definition for singly-linked list node
class Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to insert a node at a given position
void insertNode(Node *&head, int data, int position)
{
    Node* newNode = new Node(data);

    // If inserting at the head (position 0)
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Find the node before the insertion point
    int i = 1;
    Node *curr = head;
    while (i < position - 1)
    {
        curr = curr->next;
        i++;
    }
    Node *shidtedNode = curr->next;
  
    newNode->next = shidtedNode;
    curr->next = newNode;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *node = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *node4 = new Node(50);
    
    head->next = node;
    node->next = node2;
    node2->next = node3;
    node3->next = node4;
    printList(head);

    // Example usage:
    insertNode(head, 1, 1); // List: 1
    //LL after insertion of node
    printList(head); 
    return 0;
}
