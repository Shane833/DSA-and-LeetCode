#include <stdio.h>

// A is the array
// mid is the mid point floor((left + right)/2)
void merge(int A[], int left, int mid, int right){
    // Get the left of both the sub array A[left:mid] and A[mid+1:right]
    int left_size = mid - left + 1; // Using UB - LB + 1 for obtaining the size
    int right_size = right - mid; // Equivalent to right - (mid + 1) + 1

    // Indices for indexing the LOCAL left and right arrays
    int i = 0;
    int j = 0;
    int k = left; // this is the point from where we will start merging
                  // the data in the correct order

    // Create and copy data into two arrays
    int left_arr[left_size];
    int right_arr[right_size];

    for(i = 0;i < left_size;i++){
        left_arr[i] = A[left++];
    }

    for(j = 0;j < right_size;j++){
        right_arr[j] = A[++mid]; // using a pre-increment bcz the first element is at mid+1 
    }

    i = j = 0; // Reset the indices 
    
    // Repeatedly merege in the correct order
    // If any of the array is exhausted we exit out of the loop
    while(i < left_size || j < right_size){
        if(left_arr[i] <= right_arr[j]){
            A[k++] = left_arr[i++];
        }else{
            A[k++] = right_arr[j++];
        }
    }
    
    // Then we will copy the remaining data in the merged array
    while(i < left_size) A[k++] = A[i++];
    while(j < right_size) A[k++] = A[j++];
}

void mergeSort(int A[], int left, int right){
    if(left >= right) return; // Means we have gone out of bounds
                              // or we have reached a single element the base case
                              // which should already be sorted
    int q = (left + right) / 2; // This is the divide step
    mergeSort(A, left, q); // This is the conquer step working
    mergeSort(A, q+1, right); // on both the halves 
    merge(A, left, q, right);
}

int main(){
    int arr[] = {7, 3, 6, 2, 1, 5, 4};

    mergeSort(arr, 0, (sizeof(arr)/sizeof(arr[0])) - 1);

    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}
