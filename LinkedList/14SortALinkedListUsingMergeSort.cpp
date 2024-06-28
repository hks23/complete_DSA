// leetcode 148 merge sort on a linked list
#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:

     int data;
    ListNode *prev;
    ListNode *next;
    // constructor
    ListNode()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    ListNode(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ListNode *findMid(ListNode *head)
    { // using slow and fast pointer approach
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode *mergeTwoSortedLists(ListNode *left, ListNode *right)
    {
        if (left == 0)
            return right;
        if (right == 0)
            return left;

        ListNode *ans = new ListNode(-1); // making a node to point mptr pointer to it
        ListNode *mptr = ans;

        while (left != NULL and right != NULL)
        {

            if (left->data <= right->data)
            {
                mptr->next = left; // mptr points to left node
                mptr = left;       // mptr moves forward
                left = left->next; // left moves forward
            }
            else
            {
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }
        // koi list bach gayi ho to add it in the last
        if (left != NULL)
            mptr->next = left;
        if (right != NULL)
            mptr->next = right;

        return ans->next;
    }

    ListNode *sortList(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
            return head;

        ListNode *mid = findMid(head); // finding MID NODE
        ListNode *left = head;         // left points at starting node
        ListNode *right = mid->next;   // right points at second half of list
        mid->next = NULL;              // breaking the list into two parts

        left = sortList(left);   // recursion to sort left part
        right = sortList(right); // recursion to sort right part

        ListNode *mergeList = mergeTwoSortedLists(left, right);
        return mergeList;
    }
};