#include <stdio.h>
#include <math.h>

int swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int parent_idx(size_t n, int child_idx){
    if(child_idx > n - 1 || child_idx == 0) return -1; // Invalid child index
    
    return (child_idx - 1) / 2; // We offset by -1 since we are doing 2i + 1 and 2i + 2
                                // instead of 2i and 2i + 1, bcz we are dealing with indices
                                // not positions
}

int left_child_idx(size_t n, int current_idx){
    if(current_idx > n - 1) return -1; // Invalid index

    int lc_idx = (current_idx << 1) + 1;
    if(lc_idx > n - 1) return -1;
    else return lc_idx;
}

int right_child_idx(size_t n, int current_idx){
    if(current_idx > n - 1) return -1; // Invalid index

    int rc_idx =  (current_idx << 1) + 2;
    if(rc_idx > n - 1) return -1;
    else return rc_idx;

}

// Heapify / Bubble Down :
// It works on the assumption that left(i) and right(i)
// are valid heaps but A[i] is not hence we must swap
// A[i] with it dominant child hence maintaining the heap
// property. However, after we do swap either left(dominant) 
// or right(dominant) has violated the property of heap hence
// we must go down again and check with its children

void max_heapify(int arr[], size_t arr_size, int cur_idx){
    int dominant = cur_idx; // Assuming this the dominant value

    if(left_child_idx(arr_size, cur_idx) != -1){
        if(arr[left_child_idx(arr_size, cur_idx)] > arr[dominant]){
            dominant = left_child_idx(arr_size, cur_idx);
        }
    }

    if(right_child_idx(arr_size, cur_idx) != -1){
        if(arr[right_child_idx(arr_size, cur_idx)] > arr[dominant]){
            dominant = right_child_idx(arr_size, cur_idx);
        }
    }

    if(dominant != cur_idx){
       swap(arr, cur_idx, dominant);
       max_heapify(arr, arr_size, dominant);
    }
}

void build_max_heap(int arr[], size_t arr_size){
    // We will start from the non-leaf nodes
    // and keep on applying max_heapify method
    // As the leaves within themselves are valid heaps
    // This runs in O(n) time
    int first_non_leaf_idx = (arr_size - 1) / 2; // floor(n-1/2) 

    for(int i = first_non_leaf_idx;i >= 0;i--){
        max_heapify(arr, arr_size, i);
    }
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t arr_size = sizeof array / sizeof array[0];

    printf("Original Array : \n");
    for(int i = 0;i < arr_size;i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Converting to max heap : \n");
    
    build_max_heap(array, arr_size);

    for(int i = 0;i < arr_size;i++){
        printf("%d ", array[i]);
    }
}
