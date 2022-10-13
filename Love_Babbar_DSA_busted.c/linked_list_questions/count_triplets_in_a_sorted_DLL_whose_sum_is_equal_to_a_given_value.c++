#include <iostream>
#include <unordered_map>
using namespace std;
// Question: Count Triplets in a sorted DLL whose sum is equal to a given value x
// Given a sorted DLL of  distinct nodes (no two nodes have the same data) and a value x . Count triplets in the list that sum up to a given value x.
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void doublyLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    cout << "NULL"
         << "<->";
    while (ptr != NULL)
    {
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

struct Node *reverseDoublyLinkedList(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

// Native approach
// This is a native approach to solve this problem and the time complexity is : O(N^3)
//space complexity  : O(1)
/*int count_triplets(struct Node *head, int X)
{
    struct Node *p = head;
    struct Node *q = head->next;
    struct Node *r = head->next;
    int count = 0;
    while (p->next->next != NULL)
    {
        while (q->next != NULL)
        {
            while (r != NULL)
            {
                int sum = (p->data + q->data + r->data);
                if (sum == X)
                {
                    count++;
                }
                r = r->next;
            }
            q = q->next;
            r = q->next;
        }
        p = p->next;
        q = p->next;
        r = q->next;
    }
    return count;
}*/

/*int countTriplets(struct Node *head, int x)
{
    struct Node *ptr, *ptr1, *ptr2;
    int count = 0;

    // unordered_map 'um' implemented as hash table
    unordered_map<int, Node *> um;

    // insert the <node data, node pointer> tuple in 'um'
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        um[ptr->data] = ptr;

    // generate all possible pairs
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {

            // p_sum - sum of elements in the current pair
            int p_sum = ptr1->data + ptr2->data;

            // if 'x-p_sum' is present in 'um' and either of the two nodes
            // are not equal to the 'um[x-p_sum]' node
            if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1 && um[x - p_sum] != ptr2)

                // increment count
                count++;
        }
    return count / 3;
}*/

// This  is a better approach then the native approach by using unordered map
// Time complexity: O(N^2)
// space complexity: O(1)
// int count_triplets(struct Node *head, int X)
// {
//     struct Node *ptr1 = head;
//     struct Node *ptr2 = ptr1->next;
//     struct Node *ptr = head;
//     int count = 0;
//     unordered_map<int, struct Node *> um;

//     while (ptr != NULL)
//     {
//         um[ptr->data] = ptr;
//         ptr = ptr->next;
//     }

//     while (ptr1->next != NULL)
//     {
//         while (ptr2 != NULL)
//         {
//             int sum = ptr1->data + ptr2->data;

//             if (um.find(X - sum) != um.end() && um[X - sum] != ptr1 && um[X - sum] != ptr2)
//             {
//                 count++;
//             }
//             ptr2 = ptr2->next;
//         }
//         ptr1 = ptr1->next;
//         ptr2 = ptr1->next;
//     }
//     return count/3;
// }

// It's one of the most efficient way to solve this problem .
// Time complexity: O(N)
// space complexity: O(1)
int countReturns(struct Node *first, struct Node *second, int value)
{
    int count = 0;

    while (first != NULL && second != NULL && first != second && second->next != first)
    {
        if ((first->data + second->data) == value)
        {
            count++;
            first = first->next;
            second = second->prev;
        }
        else if ((first->data + second->data) > value)
        {
            second = second->prev;
        }
        else
        {
            first = first->next;
        }
    }
    return count;
}
int countTriplets(struct Node *head, int X)
{
    int count = 0;
    struct Node *current = head;
    struct Node *first = current->next;
    struct Node *last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    while (current != NULL)
    {
        first = current->next;
        count += countReturns(first, last, X - current->data);
        current =current->next;
    }
    return count;
}
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;
    Node *seventh = new Node;

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 4;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 5;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 6;
    fifth->next = sixth;

    sixth->prev = fifth;
    sixth->data = 8;
    sixth->next = seventh;

    seventh->prev = sixth;
    seventh->data = 9;
    seventh->next = NULL;

    doublyLinkedListTraversal(head);
    // int a = count_triplets(head, 15);
    int a = countTriplets(head, 15);
    printf("%d", a);
    return 0;
}