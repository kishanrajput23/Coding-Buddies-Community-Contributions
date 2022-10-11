#include <iostream>
#include <sstream>
#include<string>
#include <limits>
using namespace std;

void reverse_array(int* arr, int size)
{
    for (int i= size - 1; i >= 0; --i)
    {
        cout << arr[i] << " " ;
    }
}

int main() {
    int n;
    cin>> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(n>=1 && n<=1000)
    {
        int num_array[n];
        int i=0;
        string num_string;
        getline(cin, num_string);
        int num;
        istringstream iss(num_string);
        while(iss>>num)
        {
            if(num>=1&& num<=10000)
            {
                num_array[i] = num;
                ++i;
            }
        }
        reverse_array(num_array, n);
    }
    return 0;
}
Fo
