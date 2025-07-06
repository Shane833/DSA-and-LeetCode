// My solution for LeetCode 125 Valid Palindrome using C

#include <ctype.h>

bool isPalindrome(char* s) {
        char * r = (char *)malloc(strlen(s) + 1); // buffer for converting the string
        int i = 0;
        int j = 0;
       // Clean up the string
       for(i = 0,j = 0; s[i] != '\0';i++){
            if(isalnum(s[i])){
                r[j] = tolower(s[i]);
                j++;
            }
       }
       // at the end I append the null character
       r[j] = '\0';

       // now use the two pointer technique
       for(i = 0, j = strlen(r) - 1;i <= j;i++, j--){
            if(r[i] != r[j]){ // not palindrome
                return false;
            }
       }

    return true;
}