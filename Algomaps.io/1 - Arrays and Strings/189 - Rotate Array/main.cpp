#include <iostream>
#include <vector>

void displayVec(std::vector<int> &ivec){
    for(auto i : ivec){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// This sort of works but exceeds the time limit
void rotateArray_brute(std::vector<int> &nums, int k){
    for(int j = 0;j != k;j++){
        decltype(nums.size()) i = nums.size() - 1;
        // Copy the same element
        nums.push_back(nums[i]);
        // Still using the old index, but initial i+1 won't be an index out of bounds now
        for(; i != -1; i--){
            nums[i+1] = nums[i];
        }
        // replace the 0th element with the last
        nums[0] = nums[nums.size() - 1];

        // pop the copy
        nums.pop_back();
    }
}

// So instead of copying the array completely you have to 
// compute what the output would look like after k rotations


// Another way would be to copy the existing values and then generate new indices
void rotateArray_mysol(std::vector<int> &nums, int k){
    // Create a new vector
    std::vector<int> new_vec(nums.size()); // Create a vector with same size as nums
    auto size = nums.size();
    // Generate new indices and set the values there
    for(decltype(nums.size()) i = 0;i != nums.size();i++){
        // i + k -> generate the new index and then I mod it with the size
        // to keep it within the bounds of the array
        new_vec[(i + k) % size] = nums[i];
    }
    // copy the value again
    nums = new_vec;
    
}

int main(){
    std::vector<int> nums = {1,2,3,4,5,6,7};
    displayVec(nums);
    
    rotateArray_mysol(nums, 4);
    //rotateArray_brute(nums, 4);

    displayVec(nums);

    return 0;
}
