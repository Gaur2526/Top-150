Problem Statement Break Down : 

1. we have an array of integers nums and a target value
2. we have to return the smallest length of subarray whose sum is greater than or equal to target value
3. if no subarray found then return 0

// Solution :

// Brute force

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

          int len = INT_MAX;
    
          for(int i=0;i<nums.size();i++){
        
               int sum = 0;
               for(int j=i;j<nums.size();j++){
            
                  sum = sum + nums[j];
          
                 if(sum>=target){
                    len = min(len,j-i+1);
                }
            }
        }
        
        if(len < INT_MAX) return len;
   
        else return 0;
        
    }
};

Time complexity : O(n^2)
Space complexity : O(1)

// Optimised approach

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int len = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        for(int right = 0;right<nums.size();right++){

             sum = sum + nums[right];

             while(sum >= target){

                len = min(len,right-left+1);
                sum = sum - nums[left];
                left++;

             }
        }

        if(len == INT_MAX) return 0;

        return len;
    }
};

Time complexity : O(n)
Space complexity : O(1)
