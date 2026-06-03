#include <stdio.h>
#include <math.h>

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

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int left_child = -1, right_child = -1;
     
    size_t arr_size = sizeof array / sizeof array[0];

    for(int i = 0;i < arr_size;i++){
        if(left_child_idx(arr_size, i) == -1){
            left_child = 0;
        }else{
            left_child = array[left_child_idx(arr_size, i)];
        }         
        if(right_child_idx(arr_size, i) == -1){
            right_child = 0;
        }else{
            right_child = array[right_child_idx(arr_size,i)];
        }
        printf("%d : left child -> %d , right child -> %d\n", array[i], left_child, right_child);
    }

    printf("\n");

    int parent = 0;
    for(int i = arr_size - 1;i >= 0;i--){
       if(parent_idx(arr_size, i) == -1){
            parent = 0;
       }else{
            parent = array[parent_idx(arr_size, i)];
       }

       printf("%d : parent -> %d\n", array[i], parent);
    }
}
