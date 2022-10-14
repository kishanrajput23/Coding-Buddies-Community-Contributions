#include <iostream>
// #include <map>
using namespace std;

// Question: Given a linked list of integers , write  a function to modify the linked list such that all even numbers , appear before all the odd numbers in the modified linked list . Also , keep the order of even and odd numbers same. 


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

bool even(int data)
{
    if (data % 2 == 0)
    {
        return true;
    }
    return false;
}
bool odd(int data)
{
    if (data % 2 != 0)
    {
        return true;
    }
    return false;
}

// This  is the best approach to solve this problem, 
// time complexity : O(N)
// space complexitY: O(1)
// Approach: the idea is simple just make four pointers and then simply have them with a ptr while loop and adjust the nodes . 
struct Node *segregate_even_and_odd(struct Node *head)
{
    if(head->next == NULL) return head;
    int e = 0;
    int o = 0;
    Node* E = NULL;
    Node* O = NULL;
    Node* p;
    Node* q;
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->data%2 == 0){
            if(e == 0){
                e = 1;
                E = ptr;
                q = ptr;
            }
            else{
                q->next = ptr;
                q = ptr;
            }
        }
        if(ptr->data%2 != 0){
            if(o == 0){
                o = 1;
                O = ptr;
                p = ptr;
            }
            else{
                p->next = ptr;
                p = ptr;
            }
        }

        ptr = ptr->next;
    }
    if(O == NULL) return E;
    if(E == NULL) return O;
    q->next = NULL;
    p->next = NULL;
    q->next = O;
    return E;
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

    head->data = 17;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = fifth;

    fifth->data = 10;
    fifth->next = sixth;

    sixth->data = 5;
    sixth->next = seventh;

    seventh->data = 4;
    seventh->next = eight;

    eight->data = 1;
    eight->next = ninth;

    ninth->data = 7;
    ninth->next = tenth;

    tenth->data = 6;
    tenth->next = NULL;

    linkedListTraversal(head);
    head = segregate_even_and_odd(head);
    linkedListTraversal(head);
    return 0;
}