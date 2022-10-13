#include <iostream>
#include <map>
#include <string>

using namespace std;

//Map is an associative array
int main()
{
    map<string, int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;
    map<string, int>::iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout << (*iter).first <<" "<<iter->second<<endl;
    }

    cout<<"The size is : "<<marksMap.size()<<endl;
    cout<<"The max size is : "<<marksMap.max_size()<<endl;
    cout<<"Is it empty if empty : 1 and if not empty : 0"<<marksMap.empty()<<endl;
    return 0;
}