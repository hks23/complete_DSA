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

// Function to delete a node at a given position
void deleteNode(Node *&head, int position)
{
    // If deleting at the head (position 1)
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    // delete at Kth position
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

// Function to print the linked list

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
    deleteNode(head, 3); // List: 1
    // LL after insertion of node
    printList(head);
    return 0;
}
