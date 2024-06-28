#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    // Find the end of the first half and the start of the second half.
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half.
    ListNode *secondHalfStart = reverseList(slow);
    ListNode *firstHalfStart = head;

    // Compare the first and second halves.
    ListNode *secondHalfCopy = secondHalfStart; // To restore the list later
    bool isPalindromic = true;
    while (secondHalfStart != NULL)
    {
        if (firstHalfStart->data != secondHalfStart->data)
        {
            isPalindromic = false;
            break;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalfStart = secondHalfStart->next;
    }

    // Restore the original list (optional).
    reverseList(secondHalfCopy);

    return isPalindromic;
}

void printLL(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    ListNode *head = new ListNode(10);
    ListNode *ListNode1 = new ListNode(20);
    ListNode *ListNode2 = new ListNode(30);
    ListNode *ListNode3 = new ListNode(30);
    ListNode *ListNode4 = new ListNode(20);
    ListNode *tail = new ListNode(10);
    head->next = ListNode1;
    ListNode1->next = ListNode2;
    ListNode2->next = ListNode3;
    ListNode3->next = ListNode4;
    ListNode4->next = tail;

    printLL(head);
    cout<<isPalindrome(head);
    return 0;
}