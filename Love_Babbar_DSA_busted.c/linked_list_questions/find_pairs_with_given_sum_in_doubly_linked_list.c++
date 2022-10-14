#include <iostream>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void doublyLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    cout << "NULL"<<"<->";
    while (ptr != NULL)
    {
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout << "NULL"<<endl;
}

struct Node *reverseDoublyLinkedList(struct Node *head)
{
    struct Node* ptr1= head;
    struct Node* ptr2 =ptr1->next;

    ptr1->next= NULL;
    ptr1->prev= ptr2;

    while(ptr2 != NULL){
        ptr2->prev= ptr2->next;
        ptr2->next= ptr1;
        ptr1=ptr2;
        ptr2= ptr2->prev;
    }
    head=ptr1;
    return head;

}
void find_pairs_with_given_sum(struct Node* head, int k){
    struct Node* p= head;
    struct Node* q= head;
    while(q->next != NULL){
        q=q->next;
    }

    while(p != q && q->next != p){
        int a= p->data + q->data;
        if(a== k){
            cout<<"("<<p->data<<", "<<q->data<<") , ";
            p=p->next;
            q=q->prev;
        }
        else if(a>k){
            q=q->prev;
        }
        else{
            p=p->next;
        }
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
    find_pairs_with_given_sum(head, 7);

    return 0;
}