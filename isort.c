#include <stdio.h>
#include <stdlib.h>
#define SIZE 50 // max size of the array


// this function uses to shift i elements starting from int* arr, one cell to the right
void shift_element(int* arr, int i){

    for (int j = i; j > 0; j--){
        *(arr + (j)) = *(arr + (j-1));
    }
    
}
// this function uses to sort the array by using the method of insertion sort
void insertion_sort(int* arr, int len){

    if(len == 1){
        printf("The array is already sorted\n");
        return;
    }

    int temp;
    int i = 1;
    int j;

    while(i < len){
        j = i-1;
        while (j >= 0 && *(arr + i) <= *(arr + j)){
            if(j == 0){
                temp = *(arr + i);
                shift_element(arr, i-j);
                *arr = temp;
                break;
            }else if(*(arr + i) >= *(arr + (j-1))){
                temp = *(arr + i);
                shift_element(arr + j, i-j);
                *(arr + j) = temp;
                break;
            }else{
                j--;
            }
        }
        i++;
    }
}

//main method for getting elements from the user and insert them into the array.
//using insertion sort and print the sorted array.
int main(){

    int arr[SIZE];
    int temp;
    for (int i = 0; i < SIZE; i++){
      scanf("%d", &temp); 
      *(arr + i) = temp;  
    }
    
    insertion_sort(arr, SIZE);

    for (int i = 0; i < SIZE; i++){
        printf("%d", *(arr + i));
        if(i != SIZE-1){
            printf(",");
        }  
    }
    
    printf("\n");
    return 0;   
}

        
