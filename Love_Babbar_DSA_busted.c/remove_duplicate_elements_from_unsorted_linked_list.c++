#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

// this is done with the help of hashing table and,
// time complexity:- O(N)
// space complexity:-O(N )
void remove_duplicate_elements_in_unsorted_linked_list(struct Node *head)
{
    struct Node *p = NULL;
    struct Node *q = head;

    // Created an hashing table to store values of the linked list
    unordered_set<int> s;
    while (q != NULL)
    {
        if (s.find(q->data) != s.end())
        {
            p->next = q->next;
            Node *temp = q;
            if (q != NULL)
                q = q->next;
            temp->next = NULL;
            delete (temp);
        }
        else
        {
            s.insert(q->data);
            p = q;
            if (q != NULL)
                q = q->next;
        }
        // q = p->next;
    }
    return head;
}

// This is done by using two loops and three pointers so and the code is written by me and not seen from geeks for geeks. giving tle .
// time complexity:-- O(n square)
// space complexity:-- O(1)
struct Node *remove_duplicates(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    struct Node *r = head;
    while (p->next != NULL)
    {
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                r->next = q->next;
                q = q->next;
            }
            else
            {
                q = q->next;
                r = r->next;
            }
        }
        if (p->next == NULL)
        {
            break;
        }
        p = p->next;
        r = p;
        q = p->next;
    }
    return head;
}

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;

    head->data = 7;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 7;
    fourth->next = fifth;

    fifth->data = 7;
    fifth->next = sixth;

    sixth->data = 7;
    sixth->next = NULL;

    linkedListTraversal(head);
    // remove_duplicate_elements_in_unsorted_linked_list(head);
    head = remove_duplicates(head);
    linkedListTraversal(head);
    return 0;
}