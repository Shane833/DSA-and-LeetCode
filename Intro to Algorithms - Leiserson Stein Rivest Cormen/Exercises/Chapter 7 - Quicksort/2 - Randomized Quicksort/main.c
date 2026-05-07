#include <stdio.h>
#include <stdlib.h> // contains rand()
#include <time.h>
#include <assert.h>

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

/* Returns an integer in the range [0, n).
 *
 * Uses rand(), and so is affected-by/affects the same seed.
 */
int randint(int n) {
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    // Supporting larger values for n would requires an even more
    // elaborate implementation that combines multiple calls to rand()
    assert (n <= RAND_MAX);

    // Chop off all of the values that would cause skew...
    int end = RAND_MAX / n; // truncate skew
    assert (end > 0);
    end *= n;

    // ... and ignore results from rand() that fall above that limit.
    // (Worst case the loop condition should succeed 50% of the time,
    // so we can expect to bail out of this loop pretty quickly.)
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}

// Choosing Random numbers in a given range of numbers
// this is exclusive random function which also takes into account
// the end number
unsigned random(unsigned start, unsigned end){
    //srand((time(NULL) + rand()) % RAND_MAX); // seeding with time
    //srand((time(NULL))); // seeding with time
    unsigned nums_in_range = end - start + 1;
    nums_in_range += 1; // Adding 1 to provide exclusive range
    printf("Nums in range : %d\n", nums_in_range - 1);
    unsigned rand_num = rand() % nums_in_range;

    return start + rand_num; // or equivalent end - rand_num
}

int randomPartition(int A[], int left, int right, Compare cmp){
    unsigned nums_in_range = right - left + 1;
    nums_in_range += 1;
    unsigned i = random(left, right);
    i += left;
    printf("left :%d right : %d index : %d\n",left, right, i);
    //swap(A, i, right);
    return lomutoPartition(A, left, right, cmp);
}

void quicksort(int A[], int left, int right, Compare cmp){
    if(left < right){
        int q = randomPartition(A, left, right, cmp);
        quicksort(A, left, q - 1, cmp);
        quicksort(A, q + 1, right, cmp);
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
    //int arr[] = {100, 20, 33, 469, 5090, 6};
    display(arr, sizeof(arr)/sizeof(arr[0]));

    quicksort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, (Compare)ascOrder);

    if(isSorted(arr,sizeof(arr)/sizeof(arr[0]), (Compare)ascOrder) == 0)
    display(arr, sizeof(arr)/sizeof(arr[0]));

}
