#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    //constructor
    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node*&head){
    Node *temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int getLengthofLL(Node*head){
    int len = 0;
    Node* temp = head;
    while(temp!= NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
//Insert a Node at Head in a Doubly Linked List
void insertAtHead(Node*&head, Node*&tail, int data){
    
    //LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //LL is non empty
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
//Insert a Node at Tail in Doubly LL
void insertAtTail(Node*&head, Node*&tail, int data){
    //If LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //LL is non empty
    Node* newNode = new Node(data);
    tail->next = newNode; //tail ka next newNode pe kardo
    newNode->prev = tail; //newNode ka prev tail pe point kara do
    tail = newNode;       //tail ko shift kardo
}

//Insert a node at Kth position in a Doubly linked list
void insertAtkthNode(Node*&head, Node*&tail, int data, int pos){
    //if LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        if(pos == 1){
            insertAtHead(head, tail, data);
            return;
        }
        int len = getLengthofLL(head);
        if(pos>=len){
            insertAtTail(head, tail, data);
            return;
        }
    }
    //insertion at kth pos
    int i = 1;
    Node* prevNode = head;
    while(i<pos-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;
    // STEP-1 create a Node 
    Node* newNode = new Node(data);
    // STEP-2 
    prevNode->next = newNode;
    newNode->prev = prevNode;
    // STEP-3
    currNode->prev = newNode;
    newNode->next = currNode;
}

int main(){
    Node *head = new Node(5);
    Node* first = new  Node(10);
    Node* second = new Node(20);
    Node* third = new  Node(30);
    Node* fourth = new Node(40);

    head->next = first;
    first->prev = head;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    printLL(head);
    cout<<"The length of the Linked list is : "<<getLengthofLL(head)<<endl;
    insertAtkthNode(head, fourth, 69, 9);
    printLL(head);
}
