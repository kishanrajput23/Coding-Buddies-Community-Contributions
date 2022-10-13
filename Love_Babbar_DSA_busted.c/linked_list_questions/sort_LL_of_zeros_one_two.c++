#include <iostream>
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


struct Node* sort(struct Node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    struct Node *q = head;
    while (q != NULL)
    {
        if (q->data == 0)
        {
            count0++;
        }
        else if (q->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        q = q->next;
    }
    q = head;
    //  q->data = 0;
    //  struct Node* r=head;
    //  count0--;

    while (count0)
    {
        q->data = 0;
        count0--;
        q = q->next;
    }
    while (count1)
    {
        q->data = 1;
        count1--;
        q = q->next;
    }
    while (count2)
    {
        q->data = 2;
        count2--;
        q = q->next;
    }
    
    return head;
}
int main()
{
    Node *head = new Node;
    Node *head1 = new Node;
    Node *second1 = new Node;
    Node *third1 = new Node;
    Node *fourth1 = new Node;
    Node *fifth1 = new Node;
    Node *sixth1 = new Node;

    head1->data = 2;
    head1->next = second1;

    second1->data = 2;
    second1->next = third1;

    third1->data = 0;
    third1->next = fourth1;

    fourth1->data = 1;
    fourth1->next = fifth1;

    fifth1->data = 1;
    fifth1->next = sixth1;

    sixth1->data = 1;
    sixth1->next = NULL;

    linkedListTraversal(head1);
    sort(head1);
    linkedListTraversal(head1);

    return 0;
}