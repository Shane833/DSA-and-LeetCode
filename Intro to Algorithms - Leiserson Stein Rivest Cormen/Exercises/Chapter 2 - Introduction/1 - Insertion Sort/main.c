#include <stdio.h>

void insertionSort(size_t n, int A[n]){
    int i = 0, j = 0, key = 0;
    for(i = 1;i < n;i++){
        key = A[i]; // We need to store key before hand
        j = i - 1;  // as it will get overwritten when we do
                    // A[j+1] = A[j], as in the start j+1 = i
        while(j >= 0 && key < A[j]){
            // Keep on shifting the elements to the right
            A[j+1] = A[j];
            j--;
        }
        // Finally place the key at its correct place in the sorted sub-array 
        A[j+1] = key; // Now A[j] was the element that failed our condition 
                      // hence the correct place for our key is j+1
        // We don't perform a swap here because we have already placed other
        // elements at their correct positions and have found the position
        // for our key as well
    }
}

/*
void insertionSort(size_t n, int A[]){
    int i = 0, j = 0, key = 0;
    for(i = 1;i < n;i++){
        key = A[i]; 
        for(j = i - 1;j >= 0 && A[j] > key;j--){
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }
}
*/

int main(){
    int arr[] = {5, 1, 23, 6,7,4};

    insertionSort(sizeof(arr)/sizeof(arr[0]), arr);

    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


