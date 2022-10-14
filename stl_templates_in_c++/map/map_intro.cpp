#include<bits/stdc++.h>
using namespace std;

void display(map<string, int> &marksMap){
    map<string, int> :: iterator iter;
    for(iter = marksMap.begin(); iter != marksMap.end();iter++){
        cout<<iter->first<<"->"<<iter->second<<endl;
    }
}
// Map is an associative array 
int main(){
    map<string, int> marksMap;
    marksMap["Harry"]= 98;
    marksMap["Jack"]= 59;
    marksMap["Rohan"]= 2;
    display(marksMap);
    marksMap.insert({{"Kozume", 160}, {"kuroo", 187}});
    display(marksMap);

    cout<<"The size is : "<<marksMap.size()<<endl;
    cout<<"The max size is : "<<marksMap.max_size()<<endl;
    cout<<"The stack is empty or not 1 or 0"<<marksMap.empty()<<endl;

    if(marksMap.find("Harry") != marksMap.end()){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}