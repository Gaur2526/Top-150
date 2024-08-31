Problem Statement Break Down :

1. we have an array of integers and a target value
2. we have to return two indices such that their values sum is equal to target

Solution :

// Optimised approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;

        vector<int> index;

        for(int i=0;i<nums.size();i++){

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                
                index.push_back(mp[complement]);
                index.push_back(i);

                return index;
            }

            mp[nums[i]] = i;
        }
       
       return index;
    }
};

Time complexity : O(n)
Space complexity : O(n)
