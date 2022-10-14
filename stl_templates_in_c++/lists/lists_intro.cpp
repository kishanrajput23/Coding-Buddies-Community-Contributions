#include <bits/stdc++.h>
using namespace std;

void display(list<int> &list1)
{
    list<int>::iterator it;
    for (it = list1.begin(); it != list1.end(); it++)
    {
        cout << *it << ' ';
    }
    cout<<endl;
}
int main()
{
    // in this list is a doubly linked list and can also be used as a double ended queue of implementation by linkedlist . 
    list<int> list1; // list of 0 length

    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);
    display(list1);
    // list1.pop_back();
    // list1.pop_front();
    // list1.remove(7);
    // display(list1);

    // Sorting the list 
    list1.sort();
    // display(list1);

    list<int> list2(3); // Empty list of size 7
    // list2.push_back(0); // If we make a list of a specific size then all of them will be initialized to the zero 0 , so now we need to insert the elements and not to push them inside the doubly linked list. 
    // display(list2);
    list<int> :: iterator iter;
    iter = list2.begin();
    *iter = 45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;
    display(list2);

    list1.merge(list2);
    cout<<"After merging list2 in list1 "<<endl;
    display(list1);
    list1.sort();
    display(list1);

    //Reversing the list
    list1.reverse();
    display(list1);
    return 0;
}

