#include <iostream>
using namespace std;

class Check
{
    private:
       int i;
    public:
       Check(): i(0) {  }
       void operator ++() 
          { ++i; }
       void Display() 
          { cout << "i=" << i << endl; }
};
