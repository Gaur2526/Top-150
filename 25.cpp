Problem Statement Break Down :

1. we have an string s which contains spaces, letters , numbers etc
2. we have to remove non-alphanumeric characters from the string and spaces as well
3. we have to check whether the string is palindrome or not
4. if palindrome return true otherwise return false

Solution :

// Optimised approach

class Solution {
public:
    bool isPalindrome(string s) {
        
        string res = "";

        for(char ch : s){

            if(isalnum(ch)){
                res .push_back(tolower(ch));
            }
        }

        int left = 0;
        int right = res.size()-1;

        while(left <= right){

            if(res[left] != res[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

Time complexity : O(n)
Space complexity : O(n)
