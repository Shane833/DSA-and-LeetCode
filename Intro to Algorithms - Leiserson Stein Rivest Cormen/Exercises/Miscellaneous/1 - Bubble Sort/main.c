#include <stdio.h>
#include <stdbool.h>

void swap(int A[], int i, int j){
   int temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}

int bubbleSort(int A[], size_t n){
    bool sorted = true;    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(A[j] > A[j+1]){
                swap(A, j, j+1);
                sorted = false;
            }
        }
        if(sorted) break;
    }
}

void display(int A[], size_t n){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {45, 53, 1, 4, 43, 7};
    display(arr, sizeof(arr)/sizeof(arr[0]) );
    bubbleSort(arr, sizeof(arr)/sizeof(arr[0]) );
    display(arr, sizeof(arr)/sizeof(arr[0]) );
    return 0;
}
