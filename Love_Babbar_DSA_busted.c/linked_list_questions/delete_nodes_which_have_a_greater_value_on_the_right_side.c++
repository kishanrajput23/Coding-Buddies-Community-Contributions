#include <iostream>
// #include <map>
using namespace std;

// Question: delete nodes whic have a greater value on right side.
// given a  singly linked list, remove all the nodes which have a greater value on right side. Eg: 12->15->10->11->5->6->2->3->NULL,
// to       12-> 10->5->2

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

Node* reverseIt(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    Node* p = NULL;
    Node* q = head;
    Node* r = head->next;
    while(q != NULL){
        q->next = p;
        p = q;
        q = r;
        if(r!= NULL)r = r->next;
    }
    return p;
}

// see code library video for better understanding. 
// time complexity:O(N)
// space complexity:O(1)
struct Node *delete_nodes_which_have_a_greater_value_on_right_side(struct Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;
    head = reverseIt(head);
    Node *prev = head;
    Node *curr = head;
    int CM = head->data;
    curr = curr->next;
    Node *p = head;
    while (curr != NULL)
    {
        p->next = NULL;
        p = curr;
        if (curr->data >= CM)
        {
            CM = curr->data;
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    head = reverseIt(head);
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
    Node *seventh = new Node;
    Node *eight = new Node;
    Node *ninth = new Node;
    Node *tenth = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->next = NULL;

    // eight->data = 1;
    // eight->next = ninth;

    // ninth->data = 7;
    // ninth->next = tenth;

    // tenth->data = 6;
    // tenth->next = NULL;

    linkedListTraversal(head);
    head = delete_nodes_which_have_a_greater_value_on_right_side(head);
    linkedListTraversal(head);
    return 0;
}