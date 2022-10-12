#include <stdio.h>  
#include <conio.h>  
int main ()  
{  
    // declare an initialize x variable  
    int x = 5;  
      
    // display the result generated using the NOT (!) operator  
    printf (" The return value = %d \n", ! (x == 5));  
    printf (" The return value = %d \n", ! (x != 5));  
    printf (" The return value = %d \n", ! (x >= 3));  
    printf (" The return value = %d \n", ! (x < 3));  
      
    return 0;  
}     
