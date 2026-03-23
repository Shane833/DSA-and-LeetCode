#include <iostream>
#include <vector>
#include <cassert>

void displayVec(std::vector<int> &vec){
    for(auto data : vec){
        std::cout << data << " ";
    }
    std::cout << std::endl;
}

int removeDuplicates(std::vector<int> &nums){
    // Using similar approach as move zeroes (LeetCode 283)
    int unique_elements = 0;
    int prev = 1e3; // Assigning out of given range of [-100, 100]

    for(auto num : nums){
        if(num != prev){
            nums[unique_elements++] = num;
            prev = num;
        }
    }

    return unique_elements;
}

int main(){
    std::vector<int> ivec{0, 0, 1, 1, 1, 2, 2};
    displayVec(ivec);

    int unique_elements = removeDuplicates(ivec);
    assert(unique_elements == 3 && "Wrong Count of Unique Elements");

    displayVec(ivec);
    

}
