Problem Statement Break Down :

1. we have a number n
2. we have to determine whether it is a Happy number or not 
3. Happy number if :
   a) Starting with any positive integer, replace the number by the sum of the squares of its digits.
   b) Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
   c) Those numbers for which this process ends in 1 are happy
4. if the number is happy return true otherwise return false;


Solution : 

// Optimised approach 

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> st;

        while(n != 1 && st.find(n) == st.end()){
            st.insert(n);

            int sum = 0;

            while(n > 0){

                int digit = n%10;

                sum = sum + (digit * digit);

                n = n/10;
            }

            n = sum;
        }

        if(n == 1) return true;

        return false;
    }
};

Time complexity : cannot be determined
Space complexity : O(k) where k is the number of unique sums
