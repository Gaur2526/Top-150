Problem Statement Break Down :

1. we have an unsorted array integers 
2. we have to return the length of longest consecutive element sequence


Solution :

// Optimised approach

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());

        int longest_len = 0;

        for(int num : nums){

            if(st.find(num-1) == st.end()){

                int current_num = num;
                int current_len = 1;

                while(st.find(current_num+1) != st.end()){
                    current_num = current_num + 1;
                    current_len++;
                }

                longest_len = max(longest_len,current_len);
            }
        }

        return longest_len;
    }
};

Time complexity : O(n)
Space complexity : O(n)
