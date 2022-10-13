#include <bits/stdc++.h>
using namespace std;

unsigned long long int octalToDecimal(unsigned long long int octalNumber)
{
    unsigned long long int decimalNumber = 0, rem;
    int i = 0;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}

void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}   

int decimaltoOctal(int deciNum)
{

    // initializations
    int octalNum = 0, countval = 1;
    int dNo = deciNum;

    while (deciNum != 0)
    {

        // decimals remainder is calculated
        int remainder = deciNum % 8;

        // storing the octalvalue
        octalNum += remainder * countval;

        // storing exponential value
        countval = countval * 10;
        deciNum /= 8;
    }
    // cout << octalNum << endl;
    return octalNum;
}

int main()
{
    int a, b;
    int s1[] = {3, 2, 0, 1};
    int s2[] = {3};
    int arr[4];
    int c=0;

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[j] = s1[j] * s2[i];
            if (arr[j] > 7)
            {
                arr[j]= decimaltoOctal(arr[j]);
                if(arr[j]>=10){
                    arr[j]= arr[j]/10;
                    c= arr[j]%10;
                }
            }
            else{
                arr[j]= arr[j]+c;
                c=0;
            }
        }
    }


    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i];
    }
    
}