#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    cout<<"Displaying this vector "<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        // cout << v.at(i) << " ";
    }
    cout << endl;
}
int main()
{
    // vectors are similar to arrays but benefit to use arrays is that we could resize the vector without any preffered size. 
    // We also get so many functions with it which are really beneficial in our competitive coding. 
    // vector<int> vec1;// It's a zero length vector. 
    // int size;
    // cout<<"Enter the size of your vector"<<endl;
    // cin>>size;

    // for (int i = 0; i < size; i++)
    // {
    //     int element;
    //     cout << "The element you want to push in the vector is " << endl;
    //     cin >> element;
    //     vec1.push_back(element);
    // }
    // vec1.pop_back();
    // vector<int> :: iterator iter = vec1.begin();
    
    // display(vec1);
    // vec1.insert(iter+1, 500);
    // vec1.insert(iter+1,5, 500);
    // insert(iterator, copy, element )
    // display(vec1);

    // different ways to initialize a vector. 
    vector<char> vec2(4);// it's an character vector of size 4 
    vector<char> vec3(vec2); // it's an character vector made from vec2 itself
    vector<int> vec4(4, 34); // This is very useful initialization we have initialized vector it has 4s 34 i.e.  34 34 34 34 . 
    display(vec4);

    return 0;
}