#include <iostream>
#include <vector>

void displayVec(const std::vector<int> &nums){
    for(auto num : nums){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void swap_int(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void moveZeroes_brute(std::vector<int> &nums){
    // I can sort of use the selection sort logic here
    decltype(nums.size()) i = 0, j = 0;

    while(i != nums.size() - 1){
        if(nums[i] == 0){
            for(j = i + 1; j != nums.size() && nums[j] == 0; j++); // breaks when non-zero element is found
            //std::cout << "Indices : " << i << " " << j << std::endl;
            if(j < nums.size())
                swap_int(nums[i], nums[j]); // swap elements
        }
        i++;
    } 
}

void moveZeroes_twoptr(std::vector<int> &nums){
    decltype(nums.size()) i = 0, j = i + 1;

    while(i <= j && j < nums.size()){
        if(nums[i] == 0 && nums[j] == 0){
            j++;
        }
        else if(nums[i] == 0 && nums[j] != 0){
            swap_int(nums[i], nums[j]);
            i++; j++;
        }
        else if(nums[i] != 0 && nums[j] != 0){
            i++; j++;
        }
        else if(nums[i] != 0 && nums[j] == 0){
            i++;
        }
    }
}

void moveZeroes_optimal(std::vector<int> &nums){
    // When we encounter a non-zero we move it up in sequence
    // while maintaining the relative order

    decltype(nums.size()) i = 0;

    for(auto num : nums){
        if(num != 0){
            nums[i++] = num;
        }
    }

    // Fill the remaining places with 0
    while(i != nums.size()){
        nums[i++] = 0;
    }
}

int main(){
    std::vector<int> nums{0, 1, 3, 0, 12};   
    displayVec(nums);

    // moveZeroes_brute(nums);
    moveZeroes_optimal(nums);
    
    displayVec(nums);
}

