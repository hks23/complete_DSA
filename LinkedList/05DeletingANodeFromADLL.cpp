//code to delete a node from given position 
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

void deleteFromPosition(Node*&head, Node*&tail, int pos){
    //LL is empty
    if(head == NULL){
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    if(head->next == NULL or pos==1){
        //Single node in LL
        Node* temp = head;
        head = NULL;
        temp = NULL;
        delete temp;
        return;
    }
    int len = getLengthofLL(head);
    if(pos == len){
        //delete last node
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    //delete from somewhere middle
    //find left curr right node
    int i=1;
    Node* left = head;
    while(i<pos-1){
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;

    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}

int main(){
    Node *head = new Node(5);
    Node* first = new  Node(10);
    Node* second = new Node(20);
    Node* third = new  Node(30);
    Node* fourth = new Node(40);
    Node* tail = new Node(100);

    head->next = first;
    first->prev = head;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = tail;
    tail->prev = fourth;

    printLL(head);
    cout<<"The length of the Linked list is : "<<getLengthofLL(head)<<endl;
    // insertAtkthNode(head, fourth, 69, 9);
    deleteFromPosition(head, tail, 6);
    printLL(head);
}