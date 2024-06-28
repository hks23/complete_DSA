//leetcode 160
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
Node *getIntersectionNode(Node *headA, Node *headB) {
        Node* A=headA;
        Node* B=headB;
        while(A->next and B->next){

            if(A==B)
                return A;

            A=A->next;
            B=B->next;
        }

        if(A->next ==0){
            //B LL is larger
            //we need to find out how much larger it is
            int blen=0;
            while(B->next){
                blen++;
                B=B->next;
            }

            while(blen--)
                headB=headB->next;
            
        }

        else{
            //A is larger 
            int alen=0;
            while(A->next){
                alen++;
                A=A->next;
            }

            while(alen--)
                headA=headA->next;
            
        }
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
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

    return 0;
}
