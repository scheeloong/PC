//
//----------------------------------------------------------------------------------------
/* //
Table of Contents

1. Reverse a Linked list, T(n) = O(n),  S(n) = O(1)

2. Adding two numbers that are represented by lists



// TODO: Detect if a Linked List is circular

// TODO: Insert an element into a sorted circular linked list (Microsoft Round 1)

// TODO:
// */
//----------------------------------------------------------------------------------------
/*
// 1 Reverse a Linked list
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(1)
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node* next;
};

struct node* reverseLinkedList(struct node* head);

int main(void)
{
    struct node* head;
    struct node* a = (struct node*)malloc(sizeof(struct node));
    struct node* b = (struct node*)malloc(sizeof(struct node));
    struct node* c = (struct node*)malloc(sizeof(struct node));
    struct node* d = (struct node*)malloc(sizeof(struct node));
    a->value = 1;
    a->next = b;
    b->value = 2;
    b->next = c;
    c->value = 3;
    c->next = d;
    d->value = 4;
    d->next = NULL;
    head = a;
    struct node* curr = head;
    cout <<"Before Reversing" << endl;
    while(curr != NULL)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    // MISTAKE: Must always return pointer to head using return value.
    // You cannot return pointer to head using parameters
    // Maybe it works with double pointers??
    curr = reverseLinkedList(head);
    cout << "After Reversing" << endl;
    while(curr != NULL)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

struct node* reverseLinkedList(struct node* head)
{
    struct node* prev;
    struct node* curr;
    struct node* next;
    if(head == NULL)
        return head;
    prev = head;
    curr = head->next;
    if(curr == NULL)
        return head;

    // NOTE: MISTAKE HERE!! Forgot to point first element to NULL
    prev->next = NULL; // point first element to NULL
    while(curr!= NULL)
    {
        next= curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    head = prev; // set head to previous
    // Note: Mistake!! You can never return pointer by reference, return pointer using return value instead!!
    return head;
}
// */
//----------------------------------------------------------------------------------------
/* //
// 2 Adding two numbers that are represented by lists
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)
#include <forward_list> // singly linked list
#include <iostream>
using namespace std;

int main(void)
{
    forward_list<int> list1;
    forward_list<int> list2;
    // 55, 5->5
    list1.push_front(5);
    list1.push_front(5);
    // 36 , 6->3
    list2.push_front(3);
    list2.push_front(6);
    // note: will traverse from 6->3
    // => will print 6 3

    // Note: the result list will be in proper order
    // 36 + 55 = 91 => 9->1

    // Note: If above is not in right order, simply do reverseLinkedList algorithm first.

    for ( int& node: list1 )
    {
        cout << ' ' << node;
    }
    cout << endl;
    for ( int& node: list2 )
    {
        cout << ' ' << node;
    }
    cout << endl;
    // 55+36 = 91, 1->9
    forward_list<int> result;
    int carry = 0; // note: Carry will never be > 1, since 9+9 = 18 => 1
    while(1)
    {
        int value1 = list1.front();
        list1.pop_front();
        int value2 = list2.front();
        list2.pop_front();
//cout << "val1: " << value1 << " val2: " << value2 << " carry: " << carry << endl;
        int sum = carry + value1 + value2;
        carry = 0;
        result.push_front((sum)%10);
        if(sum >= 10)
        {
            //carry = (carry + value1 + value2)/10; //
            carry++;
        }
        if (list1.empty() || list2.empty()) break;

    }
    if(!list1.empty())
    {
        while(1)
        {
            int value1 = list1.front();
            list1.pop_front();
            int sum = carry + value1;
            carry = 0;
            result.push_front((sum)%10);

            if(sum >= 10)
            {
                carry++;
            }
            if (list1.empty()) break;
        }
    }
    else if (!list2.empty())
    {
        while(1)
        {
            int value2 = list2.front();
            list2.pop_front();
            int sum = carry + value2;
            carry = 0;
            result.push_front((sum)/10);

            if(sum >= 10)
            {
                carry++;
            }
            if (list2.empty()) break;
        }
    }

    if(carry > 0)
    {
        result.push_front(carry);
    }
    for ( int& node: result )
    {
        cout << ' ' << node;
    }
}
// */
//----------------------------------------------------------------------------------------
