#include <iostream>

bool isPerfectSquare(int num){
    int low = 1;
    int high = num / 2;
    int mid = 0;
    
   while(low <= high){
        mid = low + (high - low) / 2;
        
        if(mid * mid < num){
            low = mid + 1;
        }
        else if(mid * mid > num){
            high = mid - 1;
        }else{
            return true;
        }
   }

   return false;
}

int main(){
    std::cout << "Is Perfect Square : " << isPerfectSquare(15) << std::endl;
}
