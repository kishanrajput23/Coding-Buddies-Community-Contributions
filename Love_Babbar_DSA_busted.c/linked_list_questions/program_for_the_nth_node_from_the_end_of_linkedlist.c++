#include <iostream>
using namespace std;
// program for the  nth node from the end of linked list 
// Time complexity: O(N)
// space complexity: O(1)
struct Node
{
    char data;
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

// naive approach. 
// time complexity:O(2*N)
// space complexity:O(1)
char nth_node_from_last(struct Node* head, int n){
    struct Node* p = head;
    int count =0;
    while(p != NULL){
        count++;
        p=p->next;
    }
    p=head;
    int fromStart = count - n;
    int i=0;
    while(i != fromStart){
        p=p->next;
        i++;
    }
    return p->data;
}

// efficient approach. 
// time complexity:O(N) do in a single traversal. 
// space complexity:O(1)
// see pepcoding video if forgot. this is beeter said sliding window. 
// less intitution need to remember this question. 
char nthNode(struct Node* head,int n){
    Node* p = head;
    Node* q = head;
    for(int i = 1;i<n;i++){
        q = q->next;
        if(q == NULL) return -1;
    }
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    return p->data;
}
int main()
{
    // Node *head = new Node;
    Node *head1 = new Node;
    Node *second1 = new Node;
    Node *third1 = new Node;
    Node *fourth1 = new Node;
    Node *fifth1 = new Node;
    Node *sixth1 = new Node;

    head1->data = 'a';
    head1->next = second1;

    second1->data = 'b';
    second1->next = third1;

    third1->data = 'c';
    third1->next = fourth1;

    fourth1->data = 'd';
    fourth1->next = NULL;

    // fifth1->data = 5;
    // fifth1->next = sixth1;

    // sixth1->data = 6;
    // sixth1->next = NULL;
    int num =1;
    linkedListTraversal(head1);
    char  a = nth_node_from_last(head1, num);
    cout << "The "<<num<<" element of the linked list from last is " << a << endl;
    return 0;
}