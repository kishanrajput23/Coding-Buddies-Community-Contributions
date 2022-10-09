#include <stdio.h>
#include <stdlib.h>

int getDigits(int number){
    int digit1 = number % 10;
    int digit3 = ((number - number % 100) / 100);

    if(digit1 == digit3){
        return 1;
    }
    else{
        return 0;
    }
}


int main()
{
    int size = 100;
    int ints[size];
    int count = 0;

    for(int i = 100; i < 1000; i++){
        if(getDigits(i) == 1){
            ints[count] = i;
            count += 1;
            if(count >= 99){
                size += 1;
            }
        }
    }

    for(int a = 0; a < size; a++){
        if(ints[a] > 999 || ints[a] < 100){
            ints[a] = 0;
            continue;
        }
        printf("%d, ", ints[a]);
    }

    return 0;
}
