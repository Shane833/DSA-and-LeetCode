#include <stdio.h>
#include <stdlib.h> // contains rand()
#include <time.h>
#include <assert.h>
#include <stdint.h>

typedef int (*Compare)(int a, int b);

int ascOrder(const int a, const int b){
   return a - b; 
}

int descOrder(const int a, const int b){
    return b - a;
}

static inline void swap(int *array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

static inline int isSorted(int *array, size_t n, Compare cmp){
    for(int i = 0;i < n - 1;i++){
        if(cmp(array[i], array[i+1]) > 0) return 1; 
    }

    return 0;
}

int lomutoPartition(int A[], int left, int right, Compare cmp){
    int x = A[right]; // choosing the right most element to be the pivot
    int i = left;
    int j = left;

    for(;j < right;j++){
        if(cmp(A[j], x) < 0){
            swap(A, i, j); 
            i++;
        }
    }
    
    swap(A, i, j); // We don't have to worry about j being out of bounds
                   // bcz at the end of the loop j = right

    return i;
}

int hoarePartition(int A[], int left, int right, Compare cmp){
    int x = A[left];
    int i = left;
    int j = right;

    while(i < j){
        while(cmp(A[i], x) <= 0) i++;
        while(cmp(A[j], x) > 0) j--;

        if(i < j) swap(A, i, j);
    }

    swap(A, left, j);

    return j;
}

// Choosing Random numbers in a given range of numbers
// this is exclusive random function which also takes into account
// the end number
unsigned random(unsigned start, unsigned end){
    //srand((time(NULL) + rand()) % RAND_MAX); // seeding with time
    srand((time(NULL))); // seeding with time
    unsigned nums_in_range = end - start + 1;
    /* NOTE : Me adding this 1 was wrong
    //nums_in_range += 1; // Adding 1 to provide exclusive range
    //printf("Nums in range : %d\n", nums_in_range - 1);
    */
    unsigned rand_num = rand() % nums_in_range;

    return start + rand_num; // or equivalent is end - rand_num
}

/* Uniformely distributed numbers
static uint32_t randomInRange(uint32_t a, uint32_t b) {
    uint32_t v;
    uint32_t range;
    uint32_t upper, lower;
    uint32_t mask = 0;

    if (a == b) return a;

    if (a > b) { upper = a; lower = b; }
    else { upper = b; lower = a; }

    range = upper - lower;

    // Create a mask that's the smallest power of 2 greater than or equal to 'range'
    // This ensures that rand() & mask has a predictable power-of-2 range
    while (mask < range) {
        mask = (mask << 1) | 1;
    }

    // Generate a random value using the mask and retry if it exceeds the desired range
    while (true) {
        v = rand() & mask;
        if (v <= range) {
            return lower + v;
        }
    }
}
*/

int randomizedPartition(int A[], int left, int right, Compare cmp){
    unsigned i = random(left, right);
    swap(A, i, right);
    return hoarePartition(A, left, right, cmp);
}

void randomizedQuicksort(int A[], int left, int right, Compare cmp){
    if(left < right){
        int q = randomizedPartition(A, left, right, cmp);
        randomizedQuicksort(A, left, q - 1, cmp);
        randomizedQuicksort(A, q + 1, right, cmp);
    }
}

void display(int A[], size_t n){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2, 8, 7, 1, 3, 5, 6};
    display(arr, sizeof(arr)/sizeof(arr[0]));

    randomizedQuicksort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, (Compare)ascOrder);

    if(isSorted(arr,sizeof(arr)/sizeof(arr[0]), (Compare)ascOrder) == 0)
        display(arr, sizeof(arr)/sizeof(arr[0]));

}
