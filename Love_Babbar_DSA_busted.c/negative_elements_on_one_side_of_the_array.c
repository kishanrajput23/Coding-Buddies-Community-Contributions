#include<stdio.h>
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

// Time Complexity for this function is O(n )
void negative_elements_on_one_side(int *arr, int size){
    int temp;
    int j=0;
    for (int i = 0; i <size; i++)
    {
        if (arr[i]<0)
        {
            if (i!=j)
            {
                /* code */
            temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
            j++;
            }
            
        }
        
    }
    
}
int main(){
    int arr[]= {0, 1, -2, 3, -4, -1};
    int size= sizeof(arr)/ sizeof(int);
    printArray(arr, size);
    negative_elements_on_one_side(arr, size);
    printArray(arr, size);
    return 0;
}