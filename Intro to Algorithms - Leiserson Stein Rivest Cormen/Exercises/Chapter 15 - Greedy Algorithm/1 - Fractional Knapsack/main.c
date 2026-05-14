#include <stdio.h>
#include <stdbool.h>

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void display(int A[], size_t n){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// We can do better than O(n²)
void sortProfitbyWeight(size_t n, int p[n], int w[n]){
    bool sorted = false;
    for(int i = 0;i < n;i++){
        sorted = true;
        for(int j = 0;j < n - 1 - i;j++){
            double pw1 = (double)p[j]/w[j];
            double pw2 = (double)p[j+1]/w[j+1];
            if(pw1 < pw2){
                // swap
                swap(p, j, j+1);
                swap(w, j, j+1);
                sorted = false;
            }
        }
        if(sorted) break;
    } 
}

double fractionalKnapsack(size_t n, int p[n], int w[n], int knapsack){
    // Sort in decreasing order of profit/weight ratio
    sortProfitbyWeight(n, p, w);
   
    double x[n]; // solution vector 
    int current_weight = knapsack;

    int i = 0;
    for(;i < n;i++){
        if(w[i] > current_weight) break; // Can't accomodate
        else{
            x[i] = 1;
            current_weight = current_weight - w[i];
        }
    }
    
    if(i < n){ // i.e. some elements still remains
        x[i] = (double)current_weight / w[i]; // hence take the fractional component
    }
    
    // Obtain the max profit
    double max_profit = 0;
    for(int i = 0;i < n;i++){
        max_profit += x[i] * p[i];
    }
    
    return max_profit;
}

int main(){
    int profit[] = {25, 24, 15};
    int weight[] = {18, 15, 10};
    
    int knapsack = 20;

    double max_profit = fractionalKnapsack(sizeof profit/ sizeof profit[0], profit, weight, knapsack);

    printf("Max Profit : %0.2lf\n", max_profit);
}
