#include <stdio.h>

void display(size_t n, int A[n]){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int getMax(size_t n, int A[n]){
    int max = A[0];
    for(int i = 0;i < n;i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    return max;
}

void sortByProfit(size_t n, int p[n], int d[n]){
    int i = 0, j = 0, key1 = 0, key2 = 0;
    for(i = 1;i < n;i++){ 
        key1 = p[i]; // We need to store key as it will be overwritten
        key2 = d[i];
        for(j = i - 1;j >= 0 && key1 > p[j];j--){
            p[j+1] = p[j];
            d[j+1] = d[j];
        }
        p[j+1] =  key1;// we simply place the key at its correct place
        d[j+1] = key2; // no need to swap values
    } 
    
}

void fillArray(size_t n, int A[n]){
    for(int i = 0;i < n;i++){
        A[i] = -1;
    }
}

int jobSequencing(size_t n, int p[n], int d[n]){
    // Sort the jobs in decreasing order of their profits
    sortByProfit(n, p, d);
    // Find the max deadline    
    int queue_size = getMax(n, d);
    // Create a queue of size same as max deadline
    int job_sequence[queue_size];
    fillArray(queue_size, job_sequence);
    // now we will simply place the jobs at their
    // position in the queue
    int j = 0;
    for(int i = 0;i < n;i++){
        // we will try to find the correct place
        j = d[i] - 1; // d[i] tells the deadline (indicates the position in array)
                      // we will convert that to index
        while(j >= 0){
            if(job_sequence[j] == -1){ // We find an empty place
               job_sequence[j] = i; // put the ith job at this place
               break;
            }
            j--;
        }
    }
   // Get the profit from the sequence
   int max_profit = 0;
   for(int i = 0;i < queue_size;i++){
       if(job_sequence[i] != -1){ // Skip slots where job is not selected
                                  // i.e. basically an empty slot
           max_profit += p[job_sequence[i]];
       }
   }

   return max_profit;
}

int main(){
    // These are the jobs along with their 
    // respective profits and deadline
    int profit[] = {15, 20, 30, 18, 18, 10, 23, 16, 25};
    int deadline[] = {7, 2, 5, 3, 4, 5, 2, 7, 3};
    
    int max_profit = jobSequencing(sizeof profit/sizeof profit[0], profit, deadline);
    printf("Max Profit : %d\n", max_profit);
    return 0;
}
