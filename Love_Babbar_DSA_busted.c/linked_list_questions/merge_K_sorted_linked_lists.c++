#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "->";
        node=node->next;
    }
    cout << "NULL" << endl;
}
struct Node *mergeSorted(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;

    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeSorted(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

struct Node *merge_k_sorted_linked_list(struct Node *arr[], int last)
{

    while (last != 0)
    {
        int i = 0;
        int j = last;

        while (i < j)
        {

            arr[i] = mergeSorted(arr[i], arr[j]);
            i++;
            j--;

            if (i >= j)
            {
                last = j;
            }
        }
    }
    return arr[0];
}
struct Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    int k = 3;
    int n = 4;

    struct Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    struct Node *head = merge_k_sorted_linked_list(arr, 2);
    printList(head);
    return 0;}
