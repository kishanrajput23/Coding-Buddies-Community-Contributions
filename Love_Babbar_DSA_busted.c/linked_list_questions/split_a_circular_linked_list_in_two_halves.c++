#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
bool isEven(int count)
{
    if ((count % 2) == 0)
    {
        return true;
    }
    return false;
}

//The time complexity for this function is  O(N)
// and the space complexity is O(1)
void splittting_linked_list(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    struct Node *r = head;
    int count = 0;
    do
    {
        p = p->next;
        count++;
    } while (p != head);
    if (isEven(count))
    {
        count = (count / 2);
        while (count - 1)
        {
            cout << p->data << "->";
            p = p->next;
            count--;
        }
        cout << p->data << endl;
        q = p->next;
        r = p->next;
        p->next = head;
        while (q->next != head)
        {
            cout << q->data << "->";
            q = q->next;
        }
        cout << q->data << endl;
        q->next = r;
    }
    else
    {
        count = count / 2;
        while (count)
        {
            cout << p->data << "->";
            p = p->next;
            count--;
        }
        cout << p->data << endl;
        q = p->next;
        r = p->next;
        p->next = head;
        while (q->next != head)
        {
            cout << q->data << "->";
            q = q->next;
        }
        cout << q->data << endl;
        q->next = r;
    }
}
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = head;

    splittting_linked_list(head);

    return 0;
}